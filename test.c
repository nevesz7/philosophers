/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 21:14:34 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/08 23:13:53 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "utils.h"
#include "errors.h"
#include "messages.h"
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
