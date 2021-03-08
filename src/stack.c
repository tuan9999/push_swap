/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:46 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/08 17:18:48 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		*init_stack(int stack_data) {
	int *stack;
	int top;

	top = 0;
	stack = allocate_memory();
	push(&stack, &top, stack_data);
	return (stack);
}

int		*allocate_memory() {
	int *stack;

	stack = (int *)malloc(sizeof(int) * MIN_STACK_SIZE);
	return (stack);
}

void	push(int **stack, int *top, int data) {
	*stack[*top] = data;
	(*top)++;
}
