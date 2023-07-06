/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:14:34 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/06 00:37:08 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "errors.h"
#include <stdio.h>

void	*chef_routine(void *addr)
{
	t_chef	*kitchen;

	kitchen = (t_chef *)addr;
	printf("RATATTOUILE\n");
	(void)kitchen;
	return (NULL);
}

void	*p_routine(void *addr)
{
	t_pil	*platoon;

	platoon = (t_pil *)addr;
	printf("i just know that nothing i know\n");
	(void)platoon;
	return (NULL);
}

int	main(int argc, char *argv[])
{
	t_chef		*chef;

	chef = init_chef(argc, argv);
	if (chef == NULL)
		exit(0);
}

void	start_dinner(t_chef *chef, int argc)
{
	int				i;

	i = -1;
	chef->pils = (t_pil *)malloc(sizeof(t_pil) * argc);
	chef->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * argc);
	while (++i < argc)
		pthread_mutex_init(&chef->forks[i], NULL);
	i = 0;
	while (++i < argc)
		pthread_create(&chef->pils[i].pil, NULL, &p_routine, &chef->pils[i]);
	pthread_create(&chef->chef, NULL, &chef_routine, chef);
	pthread_join(chef->chef, NULL);
	while (--i > 0)
		pthread_join(chef->pils[i].pil, NULL);
}

t_chef	*init_chef(int argc, char *argv[])
{
	t_chef	*chef;

	if (has_error(argc, argv))
		return (NULL);
	chef = (t_chef *)malloc(sizeof(t_chef));
	chef->input = get_input(argc, argv);
	chef->start_time = get_time();
	start_dinner(chef, argc);
	return (chef);
}

t_input	get_input(int argc, char *argv[])
{
	t_input	input;

	input.nbr_of_pils = philo_atoi(argv[1]);
	input.time_to_die = philo_atoi(argv[2]);
	input.time_to_eat = philo_atoi(argv[3]);
	input.time_to_sleep = philo_atoi(argv[4]);
	if (argc == 6)
		input.times_must_eat = philo_atoi(argv[5]);
	else
		input.times_must_eat = -1;
	return (input);
}

u_long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}
