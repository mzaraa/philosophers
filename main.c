/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 10:15:39 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/29 17:48:43 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_philo(t_data	*data)
{
	int	i;

	i = 0;
	data->philo[i].left = &data->fork[i];
	data->philo[i].right = &data->fork[(data->nb_philo - 1)];
	data->philo[i].idx = i + 1;
	data->philo[i].max_eat = 0;
	data->philo[i].last_eat = 0;
	data->philo[i].data = data;
	data->philo[i].state_p = data->state;
	while (++i < data->nb_philo)
	{
		data->philo[i].idx = i + 1;
		data->philo[i].max_eat = 0;
		data->philo[i].last_eat = 0;
		data->philo[i].data = data;
		data->philo[i].left = &data->fork[i];
		data->philo[i].right = &data->fork[(i - 1)];
		data->philo[i].state_p = data->state;
	}
}

void	init_args(int ac, char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	if (data->nb_philo <= 0)
		return (wrong_arg());
	data->philo = malloc(sizeof(*data->philo) * data->nb_philo);
	data->fork = malloc(sizeof(*data->fork) * data->nb_philo);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_time_philo_must_eat = 2147483640;
	data->state = malloc(sizeof(int));
	data->state[0] = 1;
	if (ac == 6)
		data->nb_time_philo_must_eat = ft_atoi(av[5]);
	create_mutex(data);
	if (data->nb_philo == 1)
		exec_one_philo(data);
	fill_philo(data);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6 || !invalid_args(av))
		wrong_arg();
	init_args(ac, av, &data);
	if (data.nb_philo > 1)
	{
		simulation(&data);
		philo_join(&data);
		destroy_mutex_and_free(&data);
	}
	return (0);
}
