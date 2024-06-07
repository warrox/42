#include "philo_lib.h"


int	ft_atoi(const char *nbr)
{
	long	result;
	long	sign;

	sign = 1;
	result = 0;
	while (*nbr && (*nbr == ' ' || (*nbr >= 9 && *nbr <= 13)))
		++nbr;
	if (*nbr && (*nbr == '-' || *nbr == '+'))
	{
		if (*nbr++ == '-')
			sign *= -1;
	}
	while (*nbr && (*nbr >= '0' && *nbr <= '9'))
		result = (*nbr++ - '0') + result * 10;
	return (result * sign);
}

void ft_check_param(char *input, int i, t_data *data)
{
	//number_of_philosophers time_to_die time_to_eat time_to_sleep
	//[number_of_times_each_philosopher_must_eat]
	if(i == 1)// check
	{
		 data->philo_nbr = ft_atoi(input);	
	}
	if(i == 2)
	{
		data->time_die = ft_atoi(input);
	}
	if(i == 3)
	{
		data->time_eat = ft_atoi(input);
	}
	if(i == 4)
	{
		data->time_sleep = ft_atoi(input);
	}
	if(i == 5)
	{
		data->eat_cycle = ft_atoi(input);
	}
}

void ft_parser(char **input, t_data *data)
{
	int i;
	i = 0;
	while(input[i])
	{
		ft_check_param(input[i], i,data);
	}	
}
