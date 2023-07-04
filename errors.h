/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarobert <rarobert@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 21:04:54 by rarobert          #+#    #+#             */
/*   Updated: 2023/07/04 14:17:58 by rarobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <stdio.h>

# define NUMBER_OF_ARGS "ERROR: The number of argments must be 4 or 5"
# define ARG1 "Error: First argument is not a valid positive number"
# define ARG2 "Error: Second argument is not a valid positive number"
# define ARG3 "Error: Third argument is not a valid positive number"
# define ARG4 "Error: Fourth argument is not a valid positive number"
# define ARG5 "Error: Fifth argument is not a valid positive number"

int			has_error(int argc, char *argv[]);
void		throw_error(char *code);

#endif