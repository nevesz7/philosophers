/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:14:34 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/05 22:32:17 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "errors.h"
#include <stdio.h>

int	*get_input(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_philo		*philo;

	philo = init_philo(argc, argv);
	if (philo == NULL)
		exit(0);
	printf("%d\n", philo->input[0]);
	printf("%d\n", philo->input[1]);
	printf("%d\n", philo->input[2]);
	printf("%d\n", philo->input[3]);
	printf("%d\n", philo->input[4]);
}

t_philo	*init_philo(int argc, char *argv[])
{
	t_philo	*philo;

	if (has_error(argc, argv))
		return (NULL);
	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->input = get_input(argc, argv);
	philo->start_time = get_time();
	// philo->forks = (pthread_mutex_t *)malloc(argv[1] * sizeof(pthread_mutex_t));
	return (philo);
}

//input[0] = number_of_philosophers
//input[1] = time_to_die
//input[2] = time_to_eat
//input[3] = time_to_sleep
//input[4]? = number_of_times_each_philosopher_must_eat
int	*get_input(int argc, char *argv[])
{
	int	*input;
	int	i;

	i = 0;
	input = (int *)malloc(sizeof(int) * argc);
	while (++i < argc)
		input[i - 1] = philo_atoi(argv[i]);
	input[i] = -1;
	return (input);
}

u_long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}
