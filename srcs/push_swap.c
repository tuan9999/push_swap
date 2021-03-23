/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 16:34:54 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/23 17:58:29 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../get_next_line/get_next_line.h"
#include "../includes/stack.h"
#include "../includes/instruction_set.h"
#include "../includes/utility_functions.h"
#include "../libft/libft.h"
#include "../includes/merge_sort.h"

int get_middle_value(int *array, int arr_size) {
	int middle_index;
	int middle_value;
	int *temp_array;

	middle_index = arr_size / 2;
	temp_array = create_array(arr_size);
	copy_data_to_temp_array(&temp_array, array, 0, arr_size);
	printf("Given array is %d\n", arr_size);
    printArray(temp_array, arr_size);
 
    merge_sort(temp_array, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(temp_array, arr_size);
	middle_value = temp_array[middle_index];
	printf("\n*********\nmiddle val = %d\n*********\n", middle_value);
	free(temp_array);
	return middle_value;
}

void sort_stack_a_to_b(int **chunk_values, int **stack_a, int **stack_b, int *top_a, int *top_b) {
	int middle_value;
	int i;
	int chunk_index;
	int chunk;

	chunk_index = 0;
	while (*top_a > 2) {
		middle_value = get_middle_value(*stack_a, *top_a);
		i = *top_a;
		chunk = 0;
		while (i > 0) {
			if ((*stack_a)[(*top_a) - 1] < middle_value) {
				push_elem_from_stack_to_stack(stack_a, stack_b, top_a, top_b);
				chunk++;
				ft_putstr_fd("pb\n", STDOUT);
			}
			else {
				rotate_elems(stack_a, *top_a);
				ft_putstr_fd("ra\n", STDOUT);
			}
			i--;
		}
		(*chunk_values)[chunk_index] = chunk;
		chunk_index++;
		if (chunk_index % 10 == 0)
			(*chunk_values) = reallocate_array(chunk_values, chunk_index);
		print_stack(*stack_a, *stack_b, *top_a, *top_b);
	}
	if ((*stack_a)[*top_a - 1] > (*stack_a)[*top_a - 2]) {
		swap_first_two_elems(stack_a, *top_a);
		ft_putstr_fd("sa\n", STDOUT);
	}
	print_stack(*stack_a, *stack_b, *top_a, *top_b);
	reverse_elements_in_array(chunk_values, chunk_index);
}

void sort_last_two_values(int **stack_a, int **stack_b, int *top_a, int *top_b) {
	if ((*stack_b)[*top_b - 1] < (*stack_b)[*top_b - 2]) {
		swap_first_two_elems(stack_b, *top_b);
		ft_putstr_fd("sb\n", STDOUT);
	}
	push_elem_from_stack_to_stack(stack_b, stack_a, top_b, top_a);
	push_elem_from_stack_to_stack(stack_b, stack_a, top_b, top_a);
	ft_putstr_fd("pa\npa\n", STDOUT);
}

void sort_stack_b_to_a(int **chunk_values, int **stack_a, int **stack_b, int *top_a, int *top_b) {
	int i;
	int j;
	int chunk_index;
	int middle_value;

	chunk_index = 0;
	i = 0;
	while (*top_b > 0) {
		if (i == 0) {
			i = (*chunk_values)[chunk_index];
			if (i == 0)
				i = *top_b;
		}
		if (i == 1) {
			push_elem_from_stack_to_stack(stack_b, stack_a, top_b, top_a);
			ft_putstr_fd("pa\n", STDOUT);
		}
		else if (i == 2) {
			sort_last_two_values(stack_a, stack_b, top_a, top_b);
		}
		else {
			middle_value = get_middle_value((*stack_b + (*top_b - i)), i);
			j = 0;
			while (i > 2) {
				if ((*stack_b)[(*top_b) - 1] > middle_value) {
					push_elem_from_stack_to_stack(stack_b, stack_a, top_b, top_a);
					ft_putstr_fd("pa\n", STDOUT);
				}
				else {
					j++;
					rotate_elems(stack_b, *top_b);
					ft_putstr_fd("rb\n", STDOUT);
				}
				i--;
			}
			// while (j > 0) {
			// 	reverse_rotate_elems(stack_b, *top_b);
			// 	ft_putstr_fd("rrb\n", STDOUT);
			// 	j--;
			// 	i++;
			// }
		}
		if (i == 0) {
			chunk_index++;
		}
		print_stack(*stack_a, *stack_b, *top_a, *top_b);
		i++;
	}
}

int is_sorted(int *stack, int size) {
	while (size > 0) {
		if (stack[size] > stack[size - 1])
			return 1;
		size--;
	}
	return 0;
}

void sort_stack(int **stack_a, int **stack_b, int *top_a) {
	int top_b;
	int *chunk_values;

	top_b = 0;
	chunk_values = create_array(10);
	while (is_sorted(*stack_a, *top_a)) {
		sort_stack_a_to_b(&chunk_values, stack_a, stack_b, top_a, &top_b);
		// for (int i = 0; i < 10; i++) {
		// 	printf("Chunk values = %d\n", chunk_values[i]);
		// }
		sort_stack_b_to_a(&chunk_values, stack_a, stack_b, top_a, &top_b);
	}
}

int main(int argc, char **argv) {
	int *stack_a;
	int *stack_b;
	int top;

	top = 0;
	if (argc <= 1)
		return (exit_error("Error\n"));
	
	stack_a = init_stack(argc);
	stack_b = init_stack(argc);
	
	if (push_args_to_stack(&stack_a, &top, argv, argc))
		return (exit_error("Error\n"));
	
	print_stack(stack_a, stack_b, top, -1);
	sort_stack(&stack_a, &stack_b, &top);
	print_stack(stack_a, stack_b, top, -1);

	free(stack_a);
	free(stack_b);
	return (0);
}