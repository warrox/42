#include "philo_lib.h"
int main(int argc, char **argv)
{
	t_data data;
	if(argc < 4) // check if correct
	{
		printf("Not enough parameters, you should enter :  number_of_philosophers , time_to_die time_to_eat time_to_sleep, Optional : [number_of_times_each_philosopher_must_eat]\n");
		printf("Exiting Philo\n");
		exit(EXIT_FAILURE);
	}
	ft_parser(argv, &data);
}
