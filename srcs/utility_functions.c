/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 17:05:42 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/23 10:51:56 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/stack.h"
#include "../includes/utility_functions.h"

int		*reallocate_array(int **array, int size) {
	int *return_array;
	int i;

	return_array = (int *)malloc(sizeof(int) * size + 10);
	if (!return_array)
		exit_error("Malloc failed\n");
	i = 0;
	while (i < size) {
		return_array[i] = (*array)[i];
		i++;
	}
	free(array);
	return return_array;
}

int 	push_args_to_stack(int **stack, int *top, char **argument_list, int argument_count) {
	int i;
	int num;

	i = argument_count - 1;
	while (i != 0) {
		num = ft_atoi(argument_list[i]);
		if (is_in(*stack, *top, num))
			return (1);
		push(stack, top, num);
		i--;
	}
	return (0);
}

int		is_in(int *stack, int top, int num) {
	int i;

	i = 0;
	while (i < top) {
		if (num == stack[i])
			return (1);
		i++;
	}
	return (0);
}

void 	print_stack(int *stack_a, int *stack_b, int top_a, int top_b) {
	ft_putstr_fd("-------------------------------------------------------------\n", 1);
	while (top_a > 0 || top_b > 0) {
		if (top_a > 0) {
			ft_putnbr_fd(stack_a[top_a - 1], 1);
			pop(&stack_a, &top_a);
		}
		else
			ft_putstr_fd(" ", 1);
		ft_putstr_fd(" ", 1);
		if (top_b > 0) {
			ft_putnbr_fd(stack_b[top_b - 1], 1);
			pop(&stack_b, &top_b);
		}
		ft_putstr_fd("\n", 1);
	}
	ft_putstr_fd("- -\n", 1);
	ft_putstr_fd("a b\n", 1);
	ft_putstr_fd("-------------------------------------------------------------\n", 1);
}

void	reverse_elements_in_array(int **array, int size) {
	int i;
	int j;
	int temp_array[size];

	i = size - 1;
	j = 0;
	while (i >= 0) {
		temp_array[j] = (*array)[i];
		i--;
		j++;
	}

	i = 0;
	while (i < size) {
		(*array)[i] = temp_array[i];
		i++;
	}
}

int		exit_error(char *str) {
	ft_putstr_fd(str, STDOUT);
	exit (-1);
}
