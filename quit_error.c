/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:19:19 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/29 10:02:35 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	quit_error(int error)
{
	if (error == ERROR_MUTEX_INIT)
		printf("Error on pthread_mutex_init !");
	else if (error == ERROR_MUTEX_CLOSE)
		printf("Error on pthread_mutex_close !");
	else if (error == ERROR_THREAD_CREATE)
		printf("Error on pthread_create !");
	else if (error == ERROR_THREAD_DETACH)
		printf("Error on pthread_detach !");
	else if (error == ERROR_THREAD_JOIN)
		printf("Error on pthread_join !");
	return (1);
}
