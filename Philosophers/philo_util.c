#include "philo_lib.h"
void ft_time(t_data *data)
{
	(void)data; 
	struct timeval *tv = NULL;
	struct timezone *tz = NULL;
	tv = malloc(sizeof(struct timeval));
	if(!tv)
		return;
	data->ms = 0;
	gettimeofday(tv, tz);
	data->ms = tv->tv_usec / 100;
	free(tv);
}

