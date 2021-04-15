/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility_functions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 17:05:42 by tuperera      #+#    #+#                 */
/*   Updated: 2021/04/15 12:16:05 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utility_functions.h"

int check_validity_of_sorted_val_number(int *stack, int size, int count) {
	int i;

	i = count;
	while (i < size && count > 0) {
		if (stack[i] > stack[count]) {
			count--;
			i = count;
		}
		i++;
	}
	return count;
}

int number_of_sorted_values(int *stack, int size) {
	int count;

	count = 1;
	while (count < size) {
		if (stack[count] > stack[count - 1]) {
			return check_validity_of_sorted_val_number(stack, size, count - 1);
		}
		count++;
	}
	return count;
}

int is_sorted_ascending(int *stack, int size) {
	while (size > 0) {
		if (stack[size] > stack[size - 1]) {
			return 0;
		}
		size--;
	}
	return 1;
}

int is_sorted_descending(int *stack, int size) {
	while (size > 0) {
		if (stack[size] < stack[size - 1])
			return 0;
		size--;
	}
	return 1;
}

int		*reallocate_array(int **array, int size, int realloc_amount) {
	int *return_array;
	int i;

	return_array = (int *)malloc(sizeof(int) * (size + realloc_amount));
	if (!return_array)
		exit_error("Malloc failed\n");
	i = 0;
	ft_memset(return_array, 0, size + realloc_amount);
	while (i < size) {
		return_array[i] = (*array)[i];
		i++;
	}
	free(*array);
	return return_array;
}

int		is_int_overflow(char *str) {
	long value;

	value = ft_atol(str);
	if (value > INT32_MAX || value < INT32_MIN)
		return (1);
	return (0);
}

int 	push_args_to_stack(int **stack, int *top, char **argument_list, int argument_count) {
	int i;
	int num;

	i = argument_count - 1;
	while (i != 0) {
		num = ft_atoi(argument_list[i]);
		if ((!ft_isdigit(argument_list[i][0]) && (argument_list[i][0] != '-')) || is_int_overflow(argument_list[i])) {
			return (1);
		}
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

int		count_digits(int n) {
	int digit_count = 0;
	while (n) {
		n /= 10;
		digit_count++;
	}
	return digit_count;
}

void	print_spaces(int n) {
	while (n > 0) {
		ft_putstr_fd(" ", 1);
		n--;
	}
}

void	print_number_with_spaces(int n) {
	int digit_count;

	digit_count = 0;
	ft_putnbr_fd(n, STDOUT);
	digit_count = count_digits(n);
	digit_count = 3 - digit_count;
	print_spaces(digit_count);
} 

void 	print_stack(int *stack_a, int *stack_b, int top_a, int top_b) {
	
	ft_putstr_fd("-------------------------------------------------------------\n", 1);
	while (top_a > 0 || top_b > 0) {
		if (top_a > 0) {
			print_number_with_spaces(stack_a[top_a - 1]);
			pop(&stack_a, &top_a);
		}
		else
			ft_putstr_fd("   ", STDOUT);
		ft_putstr_fd(" ", STDOUT);
		if (top_b > 0) {
			ft_putnbr_fd(stack_b[top_b - 1], STDOUT);
			pop(&stack_b, &top_b);
		}
		ft_putstr_fd("\n", STDOUT);
	}
	ft_putstr_fd("--- ---\n", 1);
	ft_putstr_fd(" a   b \n", 1);
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
