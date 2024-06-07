#ifndef PHILO_LIB_H
#define PHILO_LIB_H
#include <stdio.h>
#include <stdlib.h>

typedef struct s_data
{
	int i;
	int philo_nbr;
	int philo_fork;
	int time_die;
	int time_eat;
	int time_sleep;
	int eat_cycle;
}	t_data;
void ft_parser(char **input, t_data *data);

#endif
