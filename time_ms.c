/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_ms.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:46:53 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/30 09:55:39 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_timestamp_ms	time_ms(void)
{
	static t_timestamp_ms	start = 0;
	t_timestamp_ms			current;
	t_timestamp_ms			res;
	struct timeval			time;

	gettimeofday(&time, NULL);
	current = (time.tv_sec * (long)1000) + (time.tv_usec / (long)1000);
	if (start == 0)
		start = current;
	res = current - start;
	return (res);
}

void	ft_usleep(int n)
{
	t_timestamp_ms	end_time;

	end_time = time_ms() + n;
	while (time_ms() < end_time)
		usleep(500);
}
