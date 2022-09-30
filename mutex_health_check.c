/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_health_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 08:30:20 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/30 08:37:00 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	health_check(t_data *data)
{
	int	val;

	pthread_mutex_lock(&data->health);
	val = *data->state;
	pthread_mutex_unlock(&data->health);
	return (val);
}
