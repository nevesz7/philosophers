/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:50:25 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/04 14:22:22 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "utils.h"
#include <stdio.h>

int	has_error(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc != 5 && argc != 6)
	{
		throw_error(i);
		return (TRUE);
	}
	while (++i < argc)
	{
		if (!philo_strisdigit(argv[i]) || !philo_atoi(argv[i]))
		{
			throw_error(i);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	throw_error(int code)
{
	if (code == 0)
		printf("%s\n", NUMBER_OF_ARGS);
	if (code == 1)
		printf("%s\n", ARG1);
	if (code == 2)
		printf("%s\n", ARG2);
	if (code == 3)
		printf("%s\n", ARG3);
	if (code == 4)
		printf("%s\n", ARG4);
	if (code == 5)
		printf("%s\n", ARG5);
}
