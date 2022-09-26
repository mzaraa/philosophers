/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:58:58 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/26 11:39:36 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	wrong_arg(void)
{
	printf("Usage: ./philo <number of philosophers> <time to die> \
<time to eat> <time to sleep>\n");
	exit(1);
}

int	only_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (av[i])
	{
		if (ft_strlen(av[i]) > 11)
			wrong_arg();
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				wrong_arg();
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	uint_range(char **av)
{
	int	i;
	int	useless;

	i = 1;
	while (av[i])
	{
		useless = ft_atoi(av[i]);
		i++;
	}
	return (1);
}

int	invalid_args(char **av)
{
	if (!only_int(av))
		wrong_arg();
	if (!uint_range(av))
		wrong_arg();
	return (1);
}
