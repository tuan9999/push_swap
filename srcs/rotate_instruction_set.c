/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate_instruction_set.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:22:31 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/12 16:24:08 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void rotate_elems(int **stack, int top) {
	int tmp;
	int i;
	
	tmp = (*stack)[top - 1];
	i = top - 1;
	while (i > 0) {
		(*stack)[i] = (*stack)[i - 1];
		i--;
	}
	(*stack)[0] = tmp;
}

void rotate_both(int **stack_a, int **stack_b, int top_a, int top_b) {
	rotate_elems(stack_a, top_a);
	rotate_elems(stack_b, top_b);
}
