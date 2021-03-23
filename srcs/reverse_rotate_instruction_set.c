/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate_instruction_set.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:22:16 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/12 16:25:57 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void reverse_rotate_elems(int **stack, int top) {
	int tmp;
	int i;
	
	tmp = (*stack)[0];
	i = 0;
	while (i < top) {
		(*stack)[i] = (*stack)[i + 1];
		i++;
	}
	(*stack)[top - 1] = tmp;
}

void reverse_rotate_both(int **stack_a, int **stack_b, int top_a, int top_b) {
	reverse_rotate_elems(stack_a, top_a);
	reverse_rotate_elems(stack_b, top_b);
}
