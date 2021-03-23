/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_instruction_set.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:14:31 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/09 18:31:52 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void swap_first_two_elems(int **stack, int top) {
	int tmp;
	
	if (top < 1)
		return ;
	tmp = (*stack)[top - 1];
	(*stack)[top - 1] = (*stack)[top - 2];
	(*stack)[top - 2] = tmp;
}

void swap_both(int **stack_a, int **stack_b, int top_a, int top_b) {
	swap_first_two_elems(stack_a, top_a);
	swap_first_two_elems(stack_b, top_b);
}
