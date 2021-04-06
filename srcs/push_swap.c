/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 16:34:54 by tuperera      #+#    #+#                 */
/*   Updated: 2021/04/06 13:25:25 by tuperera      ########   odam.nl         */
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
	for(int i = 0; i < arr_size; i++) {
		printf("%d ", array[i]);
	}
    merge_sort(temp_array, 0, arr_size - 1);
 
	middle_value = temp_array[middle_index];
	printf("\n*********\nmiddle val = %d\n*********\n", middle_value);
	free(temp_array);
	return middle_value;
}

void check_top_element_order(int **stack, int *top, int stack_name) {
	if ((*stack)[*top - 1] > (*stack)[*top - 2] && stack_name == 'a') {
		swap_first_two_elems(stack, *top);
		ft_putstr_fd("sa\n", STDOUT);
	}
	else if ((*stack)[*top - 1] < (*stack)[*top - 2] && stack_name == 'b') {
		swap_first_two_elems(stack, *top);
		ft_putstr_fd("sb\n", STDOUT);
	}
}

int scan_for_next_element_to_push(int *stack, int top, int middle_value) {
	int from_top;
	int from_bottom;
	int i;

	from_top = 0;
	from_bottom = -1;
	i = top;
	while (i > 0 && stack[i] >= middle_value) {
		from_top++;
		i--;
	}
	i = 0;
	while (i < top && stack[i] >= middle_value) {
		from_bottom--;
		i++;
	}
	if (from_top + from_bottom <= 0)
		return from_top;
	return from_bottom;
}

void rotate_to_next_element(int **stack, int *top, int *elements_seen, int middle_value) {
	int rotation_direction;

	rotation_direction = scan_for_next_element_to_push(*stack, *top - 1, middle_value);
	if (rotation_direction > 0) {
		while (rotation_direction != 0) {
			rotate_elems(stack, *top);
			ft_putstr_fd("ra\n", STDOUT);
			rotation_direction--;
			(*elements_seen)++;
		}
	}
	else if (rotation_direction < 0) {
		while (rotation_direction != 0) {
			reverse_rotate_elems(stack, *top);
			ft_putstr_fd("rra\n", STDOUT);
			rotation_direction++;
			(*elements_seen)++;
		}
	}
}

void sort_stack_a_to_b(int **chunk_values, int **stack_a, int **stack_b, int *top_a, int *top_b) {
	int middle_value;
	int *new_chunk_values;
	int new_chunk_index;
	int chunk_index;
	int chunk;
	int elements_seen;
	int element_list_size;

	new_chunk_values = create_array(MIN_ARRAY_SIZE);
	new_chunk_index = 0;
	chunk_index = 0;
	
	while (*top_a > 2 && is_sorted_ascending(*stack_a, *top_a - 1) == 0) {
		if ((*chunk_values)[chunk_index] > 0)
			element_list_size = (*chunk_values)[chunk_index];
		else
			element_list_size = *top_a;
		chunk = 0;
		if (element_list_size <= 2) {
			if (element_list_size == 1) {
				push_elem_from_stack_to_stack(stack_a, stack_b, top_a, top_b);
				ft_putstr_fd("pa\n", STDOUT);
				chunk++;
				element_list_size = 0;
			}
			else if (element_list_size == 2) {
				check_top_element_order(stack_a, top_a, 'a');
				push_elem_from_stack_to_stack(stack_a, stack_b, top_a, top_b);
				push_elem_from_stack_to_stack(stack_a, stack_b, top_a, top_b);
				ft_putstr_fd("pa\npa\n", STDOUT);
				element_list_size = 0;
				chunk += 2;
			}
		}
		else {
			middle_value = get_middle_value(*stack_a, *top_a);
			elements_seen = 0;
			while (elements_seen < *top_a && is_sorted_ascending(*stack_a, *top_a - 1) == 0) {
				rotate_to_next_element(stack_a, top_a, &elements_seen, middle_value);
				while ((*stack_a)[*top_a - 1] < middle_value) {
					push_elem_from_stack_to_stack(stack_a, stack_b, top_a, top_b);
					ft_putstr_fd("pb\n", STDOUT);
					chunk++;
					elements_seen++;
				}
				print_stack(*stack_a, *stack_b, *top_a, *top_b);
			}
		}
		new_chunk_values[new_chunk_index] = chunk;
		printf("Chunk = %d\n", chunk);
		new_chunk_index++;
		if (new_chunk_index % 10 == 0)
			reallocate_array(&new_chunk_values, new_chunk_index);
		sleep(3);
	}
	check_top_element_order(stack_a, top_a, 'a');
	if ((*chunk_values)[0])
		free(*chunk_values);
	reverse_elements_in_array(&new_chunk_values, new_chunk_index);
	*chunk_values = new_chunk_values;
}

int check_for_single_and_double_chunk_size(int *chunk_size, int **stack_a, int **stack_b, int *top_a, int *top_b) {
	if (*chunk_size == 1) {
		push_elem_from_stack_to_stack(stack_b, stack_a, top_b, top_a);
		ft_putstr_fd("pa\n", STDOUT);
		*chunk_size = 0;
		return (1);
	}
	else if (*chunk_size == 2) {
		check_top_element_order(stack_b, top_b, 'b');
		push_elem_from_stack_to_stack(stack_b, stack_a, top_b, top_a);
		push_elem_from_stack_to_stack(stack_b, stack_a, top_b, top_a);
		ft_putstr_fd("pa\npa\n", STDOUT);
		*chunk_size = 0;
		return (2);
	}
	return (0);
}

void check_for_reverse_rotations(int chunk_index, int *rotations, int *chunk_size, int **chunk_values, int **stack_b, int *top_b) {
	if ((*rotations) > 0 && (*chunk_values)[chunk_index + 1] != 0) {
		while ((*rotations) > 0) {
			reverse_rotate_elems(stack_b, *top_b);
			ft_putstr_fd("rrb\n", STDOUT);
			(*rotations)--;
		}
	}
	else if ((*chunk_size) == 0) {
		(*chunk_size) = (*chunk_values)[chunk_index];
	}
}

void sort_stack_b_to_a(int **chunk_values, int **stack_a, int **stack_b, int *top_a, int *top_b) {
	int chunk_size;
	int chunk_index;
	int new_chunk_size;
	int *new_chunk_values;
	int new_chunk_index;
	int elements_seen;
	int middle_value;
	int rotations;

	chunk_index = 0;
	rotations = 0;
	chunk_size = 0;
	new_chunk_index = 0;
	new_chunk_values = create_array(MIN_ARRAY_SIZE);
	while (*top_b > 0) {
		if (chunk_size == 0)
			new_chunk_size = 0;
		check_for_reverse_rotations(chunk_index, &rotations, &chunk_size, chunk_values, stack_b, top_b);
		
		printf("Chunk size in B = %d\n", chunk_size);
		middle_value = get_middle_value((*stack_b) + (*top_b - chunk_size), chunk_size);
		
		new_chunk_size += check_for_single_and_double_chunk_size(&chunk_size, stack_a, stack_b, top_a, top_b);
		print_stack(*stack_a, *stack_b, *top_a, *top_b);
		
		elements_seen = 0;
		while (elements_seen < chunk_size) {
			if ((*stack_b)[*top_b - 1] <= middle_value) {
				rotate_elems(stack_b, *top_b);
				ft_putstr_fd("rb\n", STDOUT);
				rotations++;
			}
			else {
				if ((*stack_b)[*top_b - 2] > (*stack_b)[*top_b - 1]) {
					swap_first_two_elems(stack_b, *top_b);
					ft_putstr_fd("sb\n", STDOUT);
				}
				push_elem_from_stack_to_stack(stack_b, stack_a, top_b, top_a);
				ft_putstr_fd("pa\n", STDOUT);
				new_chunk_size++;
				chunk_size--;
			}
			elements_seen++;
		}
		
		if (chunk_size == 0) {
			new_chunk_values[new_chunk_index] = new_chunk_size;
			new_chunk_index++;
			if (new_chunk_index % 10 == 0)
				new_chunk_values = reallocate_array(&new_chunk_values, new_chunk_index);
			chunk_index++;
		}
		sleep(3);
	}
	free(*chunk_values);
	reverse_elements_in_array(&new_chunk_values, new_chunk_index);
	(*chunk_values) = new_chunk_values;
}

void sort_stack(int **stack_a, int **stack_b, int *top_a) {
	int top_b;
	int *chunk_values;

	top_b = 0;
	chunk_values = create_array(MIN_ARRAY_SIZE);
	while (!is_sorted_ascending(*stack_a, *top_a - 1)) {
		printf("******************************************** AAAAAAAAAAAAAAAAA ************************************************\n");
		sort_stack_a_to_b(&chunk_values, stack_a, stack_b, top_a, &top_b);
		print_stack(*stack_a, *stack_b, *top_a, top_b);
		for (int i = 0; i < 10; i++) {
			printf("Chunk values for A = %d\n", chunk_values[i]);
		}
		printf("******************************************** BBBBBBBBBBBBBBBBB ************************************************\n");
		sort_stack_b_to_a(&chunk_values, stack_a, stack_b, top_a, &top_b);
		for (int i = 0; i < 10; i++) {
			printf("Chunk values for B = %d\n", chunk_values[i]);
		}
	}
}

int main(int argc, char **argv) {
	int *stack_a;
	int *stack_b;
	int top;

	top = 0;
	if (argc <= 1)
		return (exit_error("\n"));
	
	stack_a = init_stack(argc);
	stack_b = init_stack(argc);
	
	if (push_args_to_stack(&stack_a, &top, argv, argc))
		return (exit_error("Error\n"));
	print_stack(stack_a, stack_b, top, -1);
	sort_stack(&stack_a, &stack_b, &top);

	free(stack_a);
	free(stack_b);
	return (0);
}