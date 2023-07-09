/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 00:33:47 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 15:54:29 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "messages.h"
#include <stdio.h>

void	slip(t_pil philo)
{
	if (!can_i_do_it(philo))
		return ;
	lights_camera_action(philo.nbr, philo.start_time, SLEEP, philo.fd);
	usleep(philo.input.time_to_sleep);
}

void	think(t_pil philo)
{
	if (!can_i_do_it(philo))
		return ;
	lights_camera_action(philo.nbr, philo.start_time, THINK, philo.fd);
}

static int	fork_spoon(t_pil philo)
{
	pthread_mutex_lock(philo.fork_spoon);
	if (!can_i_do_it(philo))
	{
		pthread_mutex_unlock(philo.fork_spoon);
		return (FALSE);
	}
	lights_camera_action(philo.nbr, philo.start_time, FORK, philo.fd);
	return (TRUE);
}

static int	fork_knife(t_pil philo)
{
	if (!can_i_do_it(philo) || philo.fork_spoon == philo.fork_knife)
	{
		pthread_mutex_unlock(philo.fork_spoon);
		return (FALSE);
	}
	pthread_mutex_lock(philo.fork_knife);
	if (!can_i_do_it(philo))
	{
		pthread_mutex_unlock(philo.fork_knife);
		pthread_mutex_unlock(philo.fork_spoon);
		return (FALSE);
	}
	lights_camera_action(philo.nbr, philo.start_time, FORK, philo.fd);
	lights_camera_action(philo.nbr, philo.start_time, EAT, philo.fd);
	return (TRUE);
}

t_pil	*eat(t_pil *philo)
{
	if (!can_i_do_it(*philo))
		return (MUTS);
	if (!fork_spoon(*philo))
		return (MUTS);
	if (!fork_knife(*philo))
		return (MUTS);
	pthread_mutex_lock(philo->hunger);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->hunger);
	pthread_mutex_lock(philo->life);
	philo->last_meal[0] = get_time();
	pthread_mutex_unlock(philo->life);
	usleep(philo->input.time_to_eat);
	pthread_mutex_unlock(philo->fork_knife);
	pthread_mutex_unlock(philo->fork_spoon);
	return (philo);
}
