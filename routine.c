/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:24:12 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/30 09:27:53 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(t_timestamp_ms time, int id, char	*action)
{
	printf("%lld %d %s\n", time, id, action);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (health_check(philo->data))
		print_action(time_ms(), philo->idx, "has taken a fork");
	pthread_mutex_lock(philo->right);
	if (health_check(philo->data))
		print_action(time_ms(), philo->idx, "has taken a fork");
	if (health_check(philo->data))
		print_action(time_ms(), philo->idx, "is eating");
	pthread_mutex_lock(&philo->data->health);
	philo->max_eat++;
	philo->last_eat = time_ms();
	pthread_mutex_unlock(&philo->data->health);
	ft_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	philo_think(t_philo *philo)
{
	if (health_check(philo->data))
		print_action(time_ms(), philo->idx, "is thinking");
}

void	philo_sleep(t_philo *philo)
{
	if (health_check(philo->data))
	{
		print_action(time_ms(), philo->idx, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
	}
}
