/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:50:25 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/02 21:59:53 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include <stdio.h>

void	throw_error(char *code)
{
	if (!philo_strncmp(code, NUMBER_OF_ARGS, philo_strlen(code)))
		printf("%s\n", NUMBER_OF_ARGS);
}
