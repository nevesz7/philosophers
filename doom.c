/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 22:55:43 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 15:09:58 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "messages.h"

void	fre_e(t_chef *chef)
{
	int	i;

	i = -1;
	while (++i < chef->input.nbr_of_pils)
	{
		free(chef->pils[i].last_meal);
		pthread_mutex_destroy(&chef->forks[i]);
	}
	pthread_mutex_destroy(&chef->fd);
	pthread_mutex_destroy(&chef->dinner);
	pthread_mutex_destroy(&chef->hunger);
	pthread_mutex_destroy(&chef->life);
	pthread_mutex_destroy(&chef->time);
	free(chef->pils);
	free(chef->forks);
	free(chef);
}
