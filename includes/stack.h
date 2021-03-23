/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:35 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/23 10:41:20 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# define MIN_STACK_SIZE 10
# include <stdlib.h>

int		*init_stack(int size);
void	push(int **stack, int *top, int data);
int 	pop(int **stack, int *top);

#endif
