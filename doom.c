/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:55:43 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 11:31:45 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "messages.h"

void	stop_dinner(t_chef *chef, int who_died)
{
	pthread_mutex_lock(&chef->hunger);
	if (chef->dinner_is_over)
		lights_camera_action(who_died, chef->start_time, DIED, chef->fd);
	pthread_mutex_unlock(&chef->hunger);
}

void	fre_e(t_chef *chef)
{
	int	i;

	i = -1;
	while (++i < chef->input.nbr_of_pils)
	pthread_mutex_destroy(&chef->fd);
	pthread_mutex_destroy(&chef->forks[i]);
	pthread_mutex_destroy(&chef->dinner);
	pthread_mutex_destroy(&chef->hunger);
	pthread_mutex_destroy(&chef->life);
	pthread_mutex_destroy(&chef->time);
	free(chef->pils);
	free(chef->forks);
	free(chef);
}
