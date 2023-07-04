/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 21:52:03 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/04 14:27:25 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return ((unsigned char)s1[i] - s2[i]);
}

int	philo_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str [i])
		i++;
	return (i);
}

int	philo_atoi(const char *nptr)
{
	long int	value;
	int			i;
	int			len;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	value = 0;
	if (nptr[i] == '+')
		i++;
	len = philo_strlen(nptr);
	while (i <= len && nptr[i] >= '0' && nptr[i] <= '9')
	{
		value = (value * 10) + (nptr[i] - 48);
		i++;
	}
	return (value);
}

static int	philo_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	philo_strisdigit(const char *str)
{
	if (*str == '+')
		str++;
	if (!*str)
		return (FALSE);
	while (*str && philo_isdigit(*str))
		str++;
	if (*str)
		return (FALSE);
	return (TRUE);
}
