#include "philo_lib.h"
#include <stdio.h>

void add_philo_to_array(t_data *data)
{
	int i = 0;
	int j = 1;
	data->arrayofphilo = malloc(sizeof(int) * data->philo_nbr);
	if(!data->arrayofphilo)
		return;
	
	while(i < data->philo_nbr)
	{
		data->arrayofphilo[i] = j;
		j++;
		i++;
	}
}

void ft_check_param(char *input, int i, t_data *data)
{
	//number_of_philosophers time_to_die time_to_eat time_to_sleep
	//[number_of_times_each_philosopher_must_eat]
	if(i == 1)// check
		data->philo_nbr = ft_atoi(input);
	if(i == 2)
		data->time_die = ft_atoi(input);
	if(i == 3)
		data->time_eat = ft_atoi(input);
	if(i == 4)
		data->time_sleep = ft_atoi(input);
	if(i == 5)
		data->eat_cycle = ft_atoi(input);
}

void ft_parser(char **input, t_data *data)
{
	int i;
	i = 0;
	while(input[i])
	{
		ft_check_param(input[i], i,data);
		i++;
	}
	add_philo_to_array(data);
}
