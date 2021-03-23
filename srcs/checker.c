/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 16:34:50 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/23 10:42:25 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../get_next_line/get_next_line.h"
#include "../includes/stack.h"
#include "../includes/instruction_set.h"
#include "../includes/utility_functions.h"
#include "../libft/libft.h"

void await_instruction_loop(int **stack_a, int **stack_b, int *top_a) {
	char *buffer;
	int top_b;

	top_b = 0;
	while (get_next_line(STDIN, &buffer)) {
		if (ft_strncmp("sa\0", buffer, 3) == 0)
			swap_first_two_elems(stack_a, *top_a);
		else if (ft_strncmp("sb\0", buffer, 3) == 0)
			swap_first_two_elems(stack_b, top_b);
		else if (ft_strncmp("ss\0", buffer, 3) == 0)
			swap_both(stack_a, stack_b, *top_a, top_b);
		else if (ft_strncmp("pa\0", buffer, 3) == 0)
			push_elem_from_stack_to_stack(stack_b, stack_a, &top_b, top_a);
		else if (ft_strncmp("pb\0", buffer, 3) == 0)
			push_elem_from_stack_to_stack(stack_a, stack_b, top_a, &top_b);
		else if (ft_strncmp("ra\0", buffer, 3) == 0)
			rotate_elems(stack_a, *top_a);
		else if (ft_strncmp("rb\0", buffer, 3) == 0)
			rotate_elems(stack_b, top_b);
		else if (ft_strncmp("rr\0", buffer, 3) == 0)
			rotate_both(stack_a, stack_b, *top_a, top_b);
		else if (ft_strncmp("rra\0", buffer, 3) == 0)
			reverse_rotate_elems(stack_a, *top_a);
		else if (ft_strncmp("rrb\0", buffer, 3) == 0)
			reverse_rotate_elems(stack_b, top_b);
		else if (ft_strncmp("rrr\0", buffer, 3) == 0)
			reverse_rotate_both(stack_a, stack_b, *top_a, top_b);
		else if (ft_strncmp("exit\0", buffer, 4) == 0) {
			ft_putstr_fd("Exiting.\n", 1);
			return ;
		}
		else
			ft_putstr_fd("Error\n", 1);

		print_stack(*stack_a, *stack_b, *top_a, top_b);
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
	await_instruction_loop(&stack_a, &stack_b, &top);

	free(stack_a);
	free(stack_b);
	return (0);
}