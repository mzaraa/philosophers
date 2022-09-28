/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:06:55 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/28 16:42:57 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	int	i;

	i = 0;
	if (philo->idx % 2 == 0)
		ft_usleep((philo->data->time_to_eat / 2));
	while (philo->state != DEAD)
	{
		if ((time_ms() - philo->last_eat) > (unsigned long long)philo->data->time_to_eat)
		{
			pthread_mutex_unlock(&(philo->data->dead));
			print_action(time_ms(), philo->idx, "is dead");
		}
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		usleep(100);
	}
	return (NULL);
}

void	simulation(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_create(&data->philo[i].id, NULL, \
			(void *(*)(void *))routine, (void *)&data->philo[i]))
			quit_error(ERROR_THREAD_CREATE);
		i++;
	}
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
	if (pthread_mutex_destroy(&(data->dead)))
		quit_error(ERROR_MUTEX_CLOSE);
	free(data->fork);
	free(data->philo);
}
