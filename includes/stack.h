/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:35 by tuperera      #+#    #+#                 */
/*   Updated: 2021/04/13 15:34:21 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# define MIN_STACK_SIZE 10
# include <stdlib.h>
# include "../includes/utility_functions.h"
# include "../libft/libft.h"
# include <stdio.h>

int		*init_stack(int size);
void	push(int **stack, int *top, int data);
int 	pop(int **stack, int *top);

#endif
