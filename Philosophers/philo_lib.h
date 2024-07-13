#ifndef PHILO_LIB_H
#define PHILO_LIB_H
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
typedef struct s_philo
{
	pthread_mutex_t fork;
	int last_meal;
	int last_sleep;
	bool is_eating;
} t_philo;

typedef struct s_data
{
	pthread_mutex_t philo;
	int i;
	int philo_nbr;
	int time_die;
	int time_eat;
	int time_sleep;
	int eat_cycle;
}	t_data;
void ft_parser(char **input, t_data *data);
int	ft_atoi(const char *nbr);
#endif
