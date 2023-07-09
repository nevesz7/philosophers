/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:12:14 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 01:17:19 by rarobert         ###   ########.fr       */
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
	chef->muts.forks = malloc(sizeof(pthread_mutex_t) * amount);
	while (++i < amount)
		pthread_mutex_init(&chef->muts.forks[i], NULL);
	pthread_mutex_init(&chef->muts.dinner, NULL);
	pthread_mutex_init(&chef->muts.fd, NULL);
	pthread_mutex_init(&chef->muts.hunger, NULL);
	pthread_mutex_init(&chef->muts.life, NULL);
	pthread_mutex_init(&chef->muts.time_passed, NULL);
	i = -1;
	while (++i < amount)
		chef->pils[i] = init_philo(i, chef);
	i = -1;
	while (++i < amount)
		pthread_create(&chef->pils[i].pil, NULL, &z_routine, &chef->pils[i]);
	pthread_create(&chef->chef, NULL, &chef_routine, chef);
	pthread_join(chef->chef, NULL);
	while (--i >= 0)
		pthread_join(chef->pils[i].pil, NULL);
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
	philo.muts = &chef->muts;
	philo.dinner_is_over = chef->dinner_is_over;
	philo.input = chef->input;
	philo.start_time = chef->start_time;
	philo.last_meal = philo.start_time;
	philo.meals_eaten = 0;
	philo.fork_spoon = chef->muts.forks + index++;
	philo.fork_knife = chef->muts.forks + (index % chef->input.nbr_of_pils);
	return (philo);
}
