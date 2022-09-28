/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:06:55 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/28 18:36:33 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*monitor(t_data *data)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = &data->philo[i];
	data->dead = 1;
	while (data->dead)
	{
		if ((time_ms() - philo->last_eat) > \
			(unsigned long long)philo->data->time_to_eat)
		{
			data->dead = 0;
			print_action(time_ms(), philo->idx, "is dead");
		}
		if (philo->max_eat >= data->nb_time_philo_must_eat)
		{
			data->dead = 0;
		}
		i++;
		if (i > data->nb_philo)
			i = 0;
		philo = &data->philo[i];
	}
	return (NULL);
}

void	*routine(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->idx % 2 == 0)
		ft_usleep((philo->data->time_to_eat / 2));
	while (philo->data->dead != 0)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(100);
	}
	return (NULL);
}

void	simulation(t_data *data)
{
	int			i;
	pthread_t	checker;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].id, NULL, \
			(void *(*)(void *))routine, (void *)&data->philo[i]))
			quit_error(ERROR_THREAD_CREATE);
		i++;
	}
	if (pthread_create(&checker, NULL, \
		(void *(*)(void *))monitor, (void *)&data))
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
	}
	free(data->fork);
	free(data->philo);
}
