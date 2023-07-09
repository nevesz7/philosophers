/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:16:32 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/09 11:29:11 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "messages.h"

int	can_i_do_it(t_pil philo)
{
	pthread_mutex_lock(&philo.dinner);
	if (philo.dinner_is_over)
	{
		pthread_mutex_unlock(&philo.dinner);
		return (FALSE);
	}
	pthread_mutex_unlock(&philo.dinner);
	return (TRUE);
}

void	*z_routine(void *addr)
{
	t_pil	platoon;

	platoon = *(t_pil *)addr;
	if (platoon.nbr % 2 && platoon.nbr != 1)
		usleep(7000);
	while (can_i_do_it(platoon))
	{
		eat(platoon);
		slip(platoon);
		think(platoon);
		if (platoon.meals_eaten == platoon.input.times_must_eat)
			return (NULL);
		if (!(platoon.nbr % 2 && platoon.nbr != 1))
			usleep(3500);
	}
	return (NULL);
}
