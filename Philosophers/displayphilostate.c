#include "philo_lib.h"
#include <stdio.h>


/*◦ timestamp_in_ms X has taken a fork
◦ timestamp_in_ms X is eating
◦ timestamp_in_ms X is sleeping
◦ timestamp_in_ms X is thinking
◦ timestamp_in_ms X died*/


void display_state(t_data *data)
{
	printf("--------------------\n");
	printf("%d has taken a fork\n", data->philo_nbr);
	printf("%d is eating\n", data->philo_nbr);
	printf("%d is sleeping\n", data->philo_nbr);
	printf("%d is thinking\n",data->philo_nbr);
	printf("%d died\n", data->philo_nbr);
}
void display_all_data(t_data *data)
{
	printf("--------------------\n");
	printf("%d has taken a fork\n", data->philo_nbr);
	printf("%d is eating\n", data->philo_nbr);
	printf("%d is sleeping\n", data->philo_nbr);
	printf("%d is thinking\n",data->philo_nbr);
	printf("%d died\n", data->philo_nbr);
	printf("--------------------\n");
}
