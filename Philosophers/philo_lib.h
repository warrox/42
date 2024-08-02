/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:47:19 by whamdi            #+#    #+#             */
/*   Updated: 2024/08/02 16:57:10 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_LIB_H
# define PHILO_LIB_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

struct	s_data;

typedef struct s_philo
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				hold_right;
	int				hold_left;
	int				last_meal;
	int				id;
	int				eat_counter;
	struct s_data	*data;
	pthread_t		thread;
}					t_philo;

typedef struct s_data
{
	t_philo			*philos;
	int				philo_nbr;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				eat_cycle;
	int				flagada;
	int				flag;
	int				i;
	long			ms;
	int				s_all_eats;
	int				refresh_eatcounter;
	int				left_fork;
	int				right_fork;
	int				compare_cycleeat;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	flag_mutex;
	pthread_mutex_t	philonbr_mutex;
	pthread_mutex_t	flagada_mutex;
	pthread_mutex_t	eatcounter_mutex;
	pthread_mutex_t	lastmeal_mutex;
	pthread_mutex_t	salleat_mutex;
	pthread_mutex_t	initphilo_mutex;
	pthread_mutex_t	*forks;
	pthread_t		die_thread;
}					t_data;

/*****Philo func*****/
int					ft_parser(char **input, t_data *data);
int					ft_atoi(const char *nbr);
int					ft_time(void);
void				ft_usleep(int time, t_data *data);
bool				check_flagda(t_data *data);
int					philo_counter(t_data *data);
bool				check_flag(t_data *data);
void				*ft_isdying(void *arg);
void				ft_usleep(int time, t_data *data);
int					isdying_box(t_data *data, t_philo *philo);
int					start_simulation(t_data *data);
void				*ft_routine(void *arg);
int					mutex_init(t_data *data);
int					init_philo_thread(t_data *data, int i);
bool				fork_last(t_data *data, int left_fork, int right_fork,
						int i);
bool				fork_for_all(t_data *data, int left_fork, int right_fork,
						int i);
void				write_think(t_data *data, int i);
void				middle_init(t_data *data);
int					isdying_box1(t_data *data, int save_all_eats,
						int refresh_eatcounter, int i);
void				mutex_eatcounter(t_data *data);
void				ft_issleeping(t_data *data, int i);
#endif
