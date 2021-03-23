/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 17:08:46 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/23 10:43:18 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/stack.h"
#include "../includes/utility_functions.h"
#include "../libft/libft.h"
#include <stdio.h>

int		*init_stack(int size) {
	int *stack;

	stack = (int *)malloc(sizeof(int) * size);
	if (!stack)
		exit_error("Malloc failed.\n");
	return (stack);
}

void	push(int **stack, int *top, int data) {
	(*stack)[*top] = data;
	(*top)++;
}

int pop(int **stack, int *top) {
	int return_data;

	return_data = (*stack)[*top];
	(*top)--;
	return (return_data);
}
