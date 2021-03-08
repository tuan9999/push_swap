/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:35 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/08 19:25:05 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# define MIN_STACK_SIZE 8

int		*init_stack(int stack_data);
int		*allocate_memory();
void	push(int **stack, int *top, int data);

#endif
