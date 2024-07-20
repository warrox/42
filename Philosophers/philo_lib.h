
#ifndef PHILO_LIB_H
#define PHILO_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/time.h>
struct s_data;

typedef struct s_philo
{
    pthread_mutex_t fork;
	pthread_mutex_t write;
    int last_meal;
    int last_sleep;
    bool is_eating;
	int id;
	struct s_data *data;
} t_philo;

typedef struct s_data
{
    t_philo *philos;
    int philo_nbr;
    int *arrayofphilo;
    int time_die;
    int time_eat;
    int time_sleep;
    int eat_cycle;
	pthread_mutex_t write_mutex;
} t_data;

void ft_parser(char **input, t_data *data);
int ft_atoi(const char *nbr);

#endif
