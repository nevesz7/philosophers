/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:14:34 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/07 17:08:35 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "errors.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_chef		*chef;

	chef = init_chef(argc, argv);
	if (chef == NULL)
		exit(0);
	fre_e(chef);
	printf("hello\n");
}

u_long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec * 0.001));
}
