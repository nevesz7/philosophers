/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:12:14 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 20:23:49 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "errors.h"

t_chef	*init_chef(int argc, char *argv[])
{
	t_chef	*chef;

	if (has_error(argc, argv))
		return (MUTS);
	chef = (t_chef *)malloc(sizeof(t_chef));
	chef->input = get_input(argc, argv);
	chef->dinner_is_over = FALSE;
	chef->start_time = get_time();
	start_dinner(chef, chef->input.nbr_of_pils);
	return (chef);
}

void	start_dinner(t_chef *chef, int amount)
{
	int				i;

	i = -1;
	chef->pils = (t_pil *)malloc(sizeof(t_pil) * amount);
	chef->forks = malloc(sizeof(pthread_mutex_t) * amount);
	while (++i < amount)
		pthread_mutex_init(&chef->forks[i], MUTS);
	pthread_mutex_init(&chef->dinner, MUTS);
	pthread_mutex_init(&chef->fd, MUTS);
	pthread_mutex_init(&chef->hunger, MUTS);
	pthread_mutex_init(&chef->life, MUTS);
	pthread_mutex_init(&chef->time, MUTS);
	i = -1;
	while (++i < amount)
		chef->pils[i] = init_philo(i, chef);
	i = -1;
	while (++i < amount)
		pthread_create(&chef->pils[i].pil, MUTS, &z_routine, &chef->pils[i]);
	pthread_create(&chef->chef, MUTS, &chef_routine, chef);
	while (--i >= 0)
		pthread_join(chef->pils[i].pil, MUTS);
	pthread_join(chef->chef, MUTS);
}

t_input	get_input(int argc, char *argv[])
{
	t_input	input;

	input.nbr_of_pils = philo_atoi(argv[1]);
	input.time_to_die = philo_atoi(argv[2]);
	input.time_to_eat = philo_atoi(argv[3]) * 1000;
	input.time_to_sleep = philo_atoi(argv[4]) * 1000;
	if (argc == 6)
		input.times_must_eat = philo_atoi(argv[5]);
	else
		input.times_must_eat = -1;
	return (input);
}

t_pil	init_philo(int index, t_chef *chef)
{
	t_pil	philo;

	philo.nbr = index + 1;
	philo.dinner_is_over = &chef->dinner_is_over;
	philo.dinner = &chef->dinner;
	philo.input = chef->input;
	philo.fd = &chef->fd;
	philo.hunger = &chef->hunger;
	philo.life = &chef->life;
	philo.time = &chef->time;
	philo.start_time = chef->start_time;
	philo.last_meal = (unsigned long *)malloc(sizeof(unsigned long));
	philo.last_meal[0] = get_time();
	philo.meals_eaten = 0;
	philo.fork_spoon = chef->forks + index;
	philo.fork_knife = chef->forks + ((index + 1) % chef->input.nbr_of_pils);
	return (philo);
}
