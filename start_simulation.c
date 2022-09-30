/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:06:55 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/30 10:05:58 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(t_data *data)
{
	int		all;
	int		i;

	all = 0;
	i = 0;
	while (*data->state)
	{
		pthread_mutex_lock(&data->health);
		if (time_ms() >= (data->philo[i].last_eat + data->time_to_die))
		{
			*data->state = 0;
			print_action(time_ms(), data->philo[i].idx, "died");
		}
		else if ((data->philo[i].max_eat >= data->nb_time_philo_must_eat) \
			&& ++all >= data->nb_philo)
			*data->state = 0;
		pthread_mutex_unlock(&data->health);
		if (++i >= data->nb_philo)
		{
			all = 0;
			i = 0;
			usleep(1000);
		}
	}
	return (data);
}

void	*routine(t_philo *philo)
{
	int	i;

	i = 0;
	usleep(100);
	if ((philo->idx % 2 == 0) && health_check(philo->data))
	{
		ft_usleep((philo->data->time_to_eat / 2));
		usleep(1000);
	}
	while (health_check(philo->data))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(100);
	}
	return (philo);
}

void	simulation(t_data *data)
{
	int			i;
	pthread_t	checker;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].id, NULL, \
			(void *(*)(void *))routine, &(data->philo[i])))
			quit_error(ERROR_THREAD_CREATE);
		i++;
	}
	if (pthread_create(&checker, NULL, \
		(void *(*)(void *))monitor, data))
		quit_error(ERROR_THREAD_CREATE);
	if (pthread_join(checker, NULL))
		quit_error(ERROR_THREAD_JOIN);
}

void	philo_join(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_join(data->philo[i].id, NULL))
			quit_error(ERROR_THREAD_JOIN);
		i++;
	}
}

void	destroy_mutex_and_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_destroy(&(data->fork[i])))
			quit_error(ERROR_MUTEX_CLOSE);
		i++;
	}
	if (pthread_mutex_destroy(&(data->health)))
		quit_error(ERROR_MUTEX_CLOSE);
	free(data->fork);
	free(data->philo);
}
