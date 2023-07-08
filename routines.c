/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:16:32 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/07 16:38:00 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

void	*chef_routine(void *addr)
{
	t_chef	*kitchen;

	kitchen = (t_chef *)addr;
	printf("RATATTOUILE\n");
	(void)kitchen;
	return (NULL);
}

void	slip(t_pil philo)
{
	(void)philo;
	return ;
	// inspection(philo);
}

void	think(t_pil philo)
{
	(void)philo;
}

void	*p_routine(void *addr)
{
	t_pil	*platoon;

	platoon = (t_pil *)addr;
	printf("i just know that nothing i know\n");
	(void)platoon;
	return (NULL);
}
