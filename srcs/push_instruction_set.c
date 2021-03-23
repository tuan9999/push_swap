/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_instruction_set.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:21:56 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/12 17:11:07 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void push_elem_from_stack_to_stack(int **first_stack, int **second_stack, int *top_1, int *top_2) {
	if (*top_1 <= 0)
		return ;
	(*second_stack)[*top_2] = (*first_stack)[*top_1-1];
	(*top_2)++;
	(*top_1)--;
}
