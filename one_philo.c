/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:16:22 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/29 10:30:07 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exec_one_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo[i].left = &data->fork[i];
	data->philo[i].right = NULL;
	data->philo[i].idx = i + 1;
	data->philo[i].max_eat = 0;
	data->philo[i].last_eat = 0;
	data->philo[i].data = data;
	pthread_mutex_lock(data->philo[0].left);
	print_action(time_ms(), data->philo[0].idx, "has taken a fork");
	pthread_mutex_unlock(data->philo[0].left);
	ft_usleep(data->time_to_die);
	print_action(time_ms(), data->philo[0].idx, "is dead");
}
