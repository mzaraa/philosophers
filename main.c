/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:15:39 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/26 16:54:16 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo(t_data	*data)
{
	int	i;

	i = 0;
	data->philo[i].left = &data->fork[i];
	data->philo[i].right = &data->fork[data->nb_philo - 1];
	data->philo[i].state = EAT;
	while (++i < data->nb_philo)
	{
		data->philo[i].state = EAT;
		data->philo[i].data = data;
		data->philo[i].right = &data->fork[i - 1];
		data->philo[i].left = &data->fork[i];
	}
	create_mutex(data);
}

void	init_args(int ac, char **av, t_data *data)
{
	data->philo = malloc(sizeof(data->philo) * data->nb_philo);
	data->fork = malloc(sizeof(data->fork) * data->nb_philo);
	data->state = EAT;
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_time_philo_must_eat = -1;
	if (ac == 6)
		data->nb_time_philo_must_eat = ft_atoi(av[5]);
	fill_philo(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6 || !invalid_args(av))
		wrong_arg();
	init_args(ac, av, &data);
	simulation(&data);
	return (0);
}
