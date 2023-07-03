/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:04:54 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/02 22:22:43 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# define NUMBER_OF_ARGS "ERROR: The number of argments must be 4 or 5"

void		throw_error(char *code);
int			philo_atoi(const char *nptr);
int			philo_strlen(const char *str);
int			philo_strncmp(const char *s1, const char *s2, int n);


#endif