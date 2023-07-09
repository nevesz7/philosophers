/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:55:43 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 00:54:53 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "messages.h"

void	stop_dinner(t_chef *chef, int who_died)
{
	pthread_mutex_lock(&chef->muts.hunger);
	if (chef->dinner_is_over)
		lights_camera_action(who_died, chef->start_time, DIED, chef->muts.fd);
	pthread_mutex_unlock(&chef->muts.hunger);
}

void	fre_e(t_chef *chef)
{
	int	i;

	i = -1;
	while (++i < chef->input.nbr_of_pils)
		pthread_mutex_destroy(&chef->muts.forks[i]);
	pthread_mutex_destroy(&chef->muts.time_passed);
	free(chef->pils);
	free(chef->muts.forks);
	free(chef);
}
