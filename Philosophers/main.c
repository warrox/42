/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whamdi <whamdi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:10:52 by whamdi            #+#    #+#             */
/*   Updated: 2024/07/29 16:40:43 by whamdi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "philo_lib.h"
// #include <unistd.h>
// void ft_usleep(int time, t_data *data)
// {	
// 	long	start_time;
// 	long	elapsed_time;
// 	long	remaining_time;
//
// 	ft_time(data);
// 	start_time = data->ms;
// 	while (data->ms - start_time < time)
// 	{
// 		ft_time(data);
// 		elapsed_time =  - start_time;
// 		remaining_time = time - elapsed_time;
// 		if (remaining_time > 1000)
// 			usleep(remaining_time / 2);
// 		else
// 		{
// 			ft_time(data);
// 			while (data->ms - start_time < time)
// 				;
// 		}
// 	}
//
// }
//
// void ft_issleeping(t_data *data, int i)
// {
//     long end_time = data->ms + data->time_sleep;
//     while (data->ms < end_time)
//     {
// 		ft_time(data);
//         ft_usleep(100,data); // pour prevenir des threads qui block
//     }
// 	pthread_mutex_lock(&data->write_mutex);
// 	printf("%ld %d is sleeping[😴]\n", data->ms, i);
// 	pthread_mutex_unlock(&data->write_mutex);
// }
//
// void ft_eat(t_data *data, int i)
// {
//     ft_time(data);
//     data->philos[i].last_meal = data->ms;
//     long end_time = data->ms + data->time_eat;
//     while (data->ms < end_time)
// 		ft_time(data);
// 	pthread_mutex_lock(&data->write_mutex);
// 	printf("%ld %d is eating[🍝]\n", data->ms, i);
// 	pthread_mutex_unlock(&data->write_mutex);
// 	ft_usleep(100, data); // pour prevenir des threads qui block
// }
//
// bool ft_takefork(t_data *data, int i)
// {
//     int left_fork = i % data->philo_nbr;
//     int right_fork = (i + 1) % data->philo_nbr;
//
//     if (i == data->philo_nbr - 1)
//     {
//         pthread_mutex_lock(&data->philos[right_fork].fork);
//         ft_time(data);
//         printf("%ld %d has taken a right fork[🍴]\n", data->ms, i);
//         pthread_mutex_lock(&data->philos[left_fork].fork);
//         ft_time(data);
//         printf("%ld %d has taken a left fork[🍴]\n", data->ms, i);
//     }
//     else
//     {
//         pthread_mutex_lock(&data->philos[left_fork].fork);
//         ft_time(data);
//         printf("%ld %d has taken a left fork[🍴]\n", data->ms, i);
//         pthread_mutex_lock(&data->philos[right_fork].fork);
//         ft_time(data);
//         printf("%ld %d has taken a right fork[🍴]\n", data->ms, i);
//     }
//     return (true);
// }
//
// void *ft_isdying(void *arg) 
// {
//     int i = 0;
// 	t_data *data = (t_data *)arg;	
//     while (i < data->philo_nbr) 
//     {
// 		ft_time(data);
//         long time_since_last_meal = data->ms - data->philos[i].last_meal;
//         if (time_since_last_meal > data->time_die) 
//         {
//             pthread_mutex_lock(&data->write_mutex);
//             printf("%ld %d died\n", data->ms, data->philos[i].id);
//             pthread_mutex_unlock(&data->write_mutex);
//             exit(EXIT_FAILURE);
//         }
//         i++;
//     }
// 	return(NULL);
// }
//
// void *ft_routine(void *arg)
// {
//     t_philo *philo = (t_philo *)arg;
//     t_data *data = philo->data;
//     int i = philo->id;
//
//     while (1)
//     {
// 		ft_takefork(data, i);
// 		ft_eat(data, i);
// 		pthread_mutex_unlock(&data->philos[i % data->philo_nbr].fork);
// 		pthread_mutex_unlock(&data->philos[(i + 1) % data->philo_nbr].fork);
// 		ft_issleeping(data, i);
//         pthread_mutex_lock(&data->write_mutex);
//         printf("%ld %d is thinking[🤔]...\n", data->ms, i);
//         pthread_mutex_unlock(&data->write_mutex);
//         // ft_isdying(data);
//     }
//     return (NULL);
// }
//
// int start_simulation(t_data *data)
// {
//     int i;
// 	i = 0;
//     data->philos = malloc(sizeof(t_philo) * data->philo_nbr);
//
//     if (!data->philos)
//         return -1;
//
//     // Initialize write mutex once
//     if (pthread_mutex_init(&data->write_mutex, NULL)!= 0)
//     {
//         printf("Write mutex initialization failed\n");
//         return -1;
//     }
//
//     // Initialize philosopher data and mutexes
//     while(i < data->philo_nbr)
//     {
//         data->philos[i].id = i + 1;
//         data->philos[i].data = data;
//         if (pthread_mutex_init(&data->philos[i].fork, NULL) != 0)
//         {
//             printf("Mutex initialization failed for philosopher %d\n", i);
//             return (-1);
//         }
// 		i++;
//     }
// 	i = 0;
//     // Create threads
//     while(i < data->philo_nbr)
//     {
//         if (pthread_create(&data->philos[i].thread, NULL, ft_routine, (void *)&data->philos[i]) != 0)
//         {
//             printf("Error creating thread %d\n", i);
//             return -1;
//         }
// 		usleep(50);
// 		i++;
//     }
// 	if(pthread_create(&data->die_thread, NULL, ft_isdying, (void *)&data) != 0)
// 	{
// 		printf("Error creating thread %d\n", i);
//         return (-1);
// 	}
//
//     // Join threads
//     i = 0;
// 	while(i < data->philo_nbr)
//     {
//         if (pthread_join(data->philos[i].thread, NULL) != 0)
//         {
//             printf("Error joining thread %d\n", i);
//             return (-1);
//         }
// 		i++;
//     }
// 	i = 0;
//     while(i < data->philo_nbr)
//     {
//         pthread_mutex_destroy(&data->philos[i].fork);
// 		i++;
//     }
//
//     pthread_mutex_destroy(&data->write_mutex);
//
//     free(data->philos);
//     return (0);
// }
//
// int main(int argc, char **argv)
// {
//     t_data data;
// 	data.counter = 0;
//     if (argc < 5)
//     {
//         printf("Not enough parameters, you should enter: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep. Optional: [number_of_times_each_philosopher_must_eat]\n");
//         printf("Exiting Philo\n");
//         exit(EXIT_FAILURE);
//     }
//
//     if (ft_parser(argv, &data) == -1)
//         return -1;
//     ft_time(&data);
//     start_simulation(&data);
//
//     return (0);
// }
//

#include "philo_lib.h"

void ft_usleep(int time, t_data *data) {
    long start_time;
    ft_time(data);
    start_time = data->ms;
    while (data->ms - start_time < time) 
	{
        usleep(500); // Sleep for a short duration to prevent busy-waiting
        ft_time(data);
    }
}

void ft_issleeping(t_data *data, int i) {
    pthread_mutex_lock(&data->write_mutex);
    ft_time(data);
    printf("%ld %d is sleeping[😴]\n", data->ms, i);
    pthread_mutex_unlock(&data->write_mutex);
    ft_usleep(data->time_sleep, data);
}

void ft_eat(t_data *data, int i) 
{
    pthread_mutex_lock(&data->write_mutex);
    ft_time(data);
    data->philos[i].last_meal = data->ms;
    printf("%ld %d is eating[🍝]\n", data->ms, i);
    pthread_mutex_unlock(&data->write_mutex);
    ft_usleep(data->time_eat, data);
}

bool ft_takefork(t_data *data, int i) {
    int left_fork = i % data->philo_nbr;
    int right_fork = (i + 1) % data->philo_nbr;

    if (i == data->philo_nbr - 1) {
        pthread_mutex_lock(&data->philos[right_fork].fork);
        ft_time(data);
        printf("%ld %d has taken a right fork[🍴]\n", data->ms, i);
        pthread_mutex_lock(&data->philos[left_fork].fork);
        ft_time(data);
        printf("%ld %d has taken a left fork[🍴]\n", data->ms, i);
    } else {
        pthread_mutex_lock(&data->philos[left_fork].fork);
        ft_time(data);
        printf("%ld %d has taken a left fork[🍴]\n", data->ms, i);
        pthread_mutex_lock(&data->philos[right_fork].fork);
        ft_time(data);
        printf("%ld %d has taken a right fork[🍴]\n", data->ms, i);
    }
    return true;
}

void *ft_isdying(void *arg) {
    t_data *data = (t_data *)arg;	
    while (1) {
        int i = 0;
        while (i < data->philo_nbr) {
            ft_time(data);
            long time_since_last_meal = data->ms - data->philos[i].last_meal;
            if (time_since_last_meal > data->time_die) {
                pthread_mutex_lock(&data->write_mutex);
                printf("%ld %d died\n", data->ms, data->philos[i].id);
                pthread_mutex_unlock(&data->write_mutex);
                exit(EXIT_FAILURE);
            }
            i++;
        }
        usleep(1000); // Check every 1 millisecond
    }
    return (NULL);
}

void *ft_routine(void *arg) {
    t_philo *philo = (t_philo *)arg;
    t_data *data = philo->data;
    int i = philo->id;

    while (1) 
	{
        ft_takefork(data, i);
        ft_eat(data, i);
        pthread_mutex_unlock(&data->philos[i % data->philo_nbr].fork);
        pthread_mutex_unlock(&data->philos[(i + 1) % data->philo_nbr].fork);
        ft_issleeping(data, i);
        pthread_mutex_lock(&data->write_mutex);
        ft_time(data);
        printf("%ld %d is thinking[🤔]...\n", data->ms, i);
        pthread_mutex_unlock(&data->write_mutex);
    }
    return (NULL);
}

int start_simulation(t_data *data) {
    int i = 0;
    data->philos = malloc(sizeof(t_philo) * data->philo_nbr);
    if (!data->philos)
        return -1;

    if (pthread_mutex_init(&data->write_mutex, NULL) != 0) {
        printf("Write mutex initialization failed\n");
        return -1;
    }

    while (i < data->philo_nbr) {
        data->philos[i].id = i + 1;
        data->philos[i].data = data;
        if (pthread_mutex_init(&data->philos[i].fork, NULL) != 0) {
            printf("Mutex initialization failed for philosopher %d\n", i);
            return (-1);
        }
        i++;
    }

    i = 0;
    while (i < data->philo_nbr) 
	{
        if (pthread_create(&data->philos[i].thread, NULL, ft_routine, (void *)&data->philos[i]) != 0) {
            printf("Error creating thread %d\n", i);
            return (-1);
        }
        usleep(50);
        i++;
    }

    if (pthread_create(&data->die_thread, NULL, ft_isdying, (void *)data) != 0) {
        printf("Error creating death monitoring thread\n");
        return (-1);
    }

    i = 0;
    while (i < data->philo_nbr) 
	{
        if (pthread_join(data->philos[i].thread, NULL) != 0) {
            printf("Error joining thread %d\n", i);
            return (-1);
        }
        i++;
    }

    i = 0;
    while (i < data->philo_nbr) 
	{
        pthread_mutex_destroy(&data->philos[i].fork);
        i++;
    }

    pthread_mutex_destroy(&data->write_mutex);

    free(data->philos);
    return (0);
}

int main(int argc, char **argv) 
{
    t_data data;

    if (argc < 5) 
	{
        printf("Not enough parameters, you should enter: number_of_philosophers, time_to_die, time_to_eat, time_to_sleep. Optional: [number_of_times_each_philosopher_must_eat]\n");
        printf("Exiting Philo\n");
        exit(EXIT_FAILURE);
    }

    if (ft_parser(argv, &data) == -1)
        return (-1);
    ft_time(&data);
    start_simulation(&data);

    return (0);
}

