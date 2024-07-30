#ifndef PHILO_LIB_H
#define PHILO_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>

struct s_data;

typedef struct s_philo {
    pthread_mutex_t fork;
    int last_meal;
    int id;
    struct s_data *data;
    pthread_t thread;
} t_philo;

typedef struct s_data {
    t_philo *philos;
    int philo_nbr;
    int time_die;
    int time_eat;
    int time_sleep;
	int eat_cycle;
    int flag;
	long ms;
    pthread_mutex_t write_mutex;
	pthread_mutex_t flag_mutex;
    pthread_t die_thread;
} t_data;

/*****Philo func*****/
int ft_parser(char **input, t_data *data);
int ft_atoi(const char *nbr);
int ft_time(void);
void ft_usleep(int time, t_data *data);

#endif
