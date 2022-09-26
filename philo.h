/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:36:26 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/26 16:55:05 by mzaraa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdbool.h>

# define SLEEP 0
# define EAT 1
# define THINK 2
# define DEAD 3

# define ERROR_MUTEX_INIT 4
# define ERROR_MUTEX_CLOSE 3
# define ERROR_THREAD_CREATE 3
# define ERROR_THREAD_DETACH 3
# define ERROR_THREAD_JOIN 3

typedef struct s_data
{
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	int				state;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_philo_must_eat;
}	t_data;

typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		id;
	int				state;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	int				max_eat;
}	t_philo;

/*			Utils		*/
int		ft_atoi(char *s);
void	ft_putstr(char *s);
int		ft_isdigit(int c);
int		ft_strlen(const char *str);

/*		Error		*/
void	quit_error(int error);

/*		Parsing		*/
int		invalid_args(char **av);
void	wrong_arg(void);
void	create_mutex(t_data *data);

/*		Simulation		*/
void	simulation(t_data *data);

#endif
