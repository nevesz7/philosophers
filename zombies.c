/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:16:32 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 20:31:45 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "messages.h"

int	can_i_do_it(t_pil philo)
{
	pthread_mutex_lock(philo.dinner);
	if (philo.dinner_is_over[0])
	{
		pthread_mutex_unlock(philo.dinner);
		return (FALSE);
	}
	pthread_mutex_unlock(philo.dinner);
	return (TRUE);
}

void	*z_routine(void *addr)
{
	t_pil	*platoon;

	platoon = (t_pil *)addr;
	if (platoon->nbr % 2)
		usleep(70000);
	while (can_i_do_it(*platoon))
	{
		platoon = eat(platoon);
		if (!platoon || platoon->meals_eaten == platoon->input.times_must_eat)
			return (MUTS);
		slip(*platoon);
		think(*platoon);
		if (!(platoon->nbr % 2))
			usleep(70000);
	}
	return (MUTS);
}
