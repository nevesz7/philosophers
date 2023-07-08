/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:12:14 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/07 17:11:57 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "errors.h"

t_chef	*init_chef(int argc, char *argv[])
{
	t_chef	*chef;

	if (has_error(argc, argv))
		return (NULL);
	chef = (t_chef *)malloc(sizeof(t_chef));
	chef->input = get_input(argc, argv);
	chef->start_time = get_time();
	start_dinner(chef, chef->input.nbr_of_pils);
	return (chef);
}

void	start_dinner(t_chef *chef, int amount)
{
	int				i;

	i = -1;
	chef->pils = (t_pil *)malloc(sizeof(t_pil) * amount);
	chef->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * amount);
	while (++i < amount)
		pthread_mutex_init(&chef->forks[i], NULL);
	i = -1;
	while (++i < amount)
		chef->pils[i] = init_philo(i, chef);
	i = -1;
	while (++i < amount)
		pthread_create(&chef->pils[i].pil, NULL, &p_routine, &chef->pils[i]);
	pthread_create(&chef->chef, NULL, &chef_routine, chef);
	pthread_join(chef->chef, NULL);
	while (--i >= 0)
		pthread_join(chef->pils[i].pil, NULL);
	while (++i < amount)
		pthread_mutex_destroy(chef->forks + i);
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

t_pil	init_philo(int index, t_chef *chef)
{
	t_pil	philo;

	philo.nbr = index + 1;
	philo.input = chef->input;
	philo.start_time = chef->start_time;
	philo.last_meal = philo.start_time;
	philo.fork_spoon = chef->forks + index;
	if (index < chef->input.nbr_of_pils)
		philo.fork_knife = chef->forks + index + 1;
	else
		philo.fork_knife = chef->forks;
	return (philo);
}
