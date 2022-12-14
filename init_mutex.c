/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:37:16 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/30 08:33:29 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&(data->fork[i]), NULL))
			quit_error(ERROR_MUTEX_INIT);
		i++;
	}
	if (pthread_mutex_init(&data->health, NULL))
		quit_error(ERROR_MUTEX_INIT);
}
