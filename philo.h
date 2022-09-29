/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzaraa <mzaraa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 11:36:26 by mzaraa            #+#    #+#             */
/*   Updated: 2022/09/29 15:24:00 by mzaraa           ###   ########.fr       */
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
# include <sys/time.h>
# include <limits.h>

# define SLEEP 0
# define EAT 1
# define THINK 2
# define DEAD 3

# define ERROR_MUTEX_INIT 4
# define ERROR_MUTEX_CLOSE 5
# define ERROR_THREAD_CREATE 6
# define ERROR_THREAD_DETACH 7
# define ERROR_THREAD_JOIN 8

typedef unsigned long long int	t_timestamp_ms;

typedef struct s_data
{
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
	int				*state;
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
	int				idx;
	int				*state_p;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
	int				max_eat;
	t_timestamp_ms	last_eat;
}	t_philo;

/*			Utils		*/
int				ft_atoi(char *s);
void			ft_putstr(char *s);
int				ft_isdigit(int c);
int				ft_strlen(const char *str);

/*		Error		*/
int				quit_error(int error);

/*		Parsing		*/
int				invalid_args(char **av);
void			wrong_arg(void);
void			create_mutex(t_data *data);

/*		Start_simulation		*/
void			simulation(t_data *data);
void			exec_one_philo(t_data *data);
void			philo_join(t_data *data);
void			destroy_mutex_and_free(t_data *data);

/*		Routine		*/
void			philo_eat(t_philo *philo);
void			philo_think(t_philo *philo);
void			philo_sleep(t_philo *philo);
void			print_action(t_timestamp_ms time, int id, char	*action);

/*		Time		*/
t_timestamp_ms	time_ms(void);
void			ft_usleep(int n);

#endif
