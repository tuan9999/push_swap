/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   instruction_set.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/09 15:14:14 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/09 15:59:11 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTION_SET_H
# define INSTRUCTION_SET_H

void swap_first_two_elems(int **stack, int top);
void swap_both(int **stack_a, int **stack_b, int top_a, int top_b);
void push_elem_from_stack_to_stack(int **first_stack, int **second_stack, int *top_1, int *top_2);
void rotate_elems(int **stack, int top);
void rotate_both(int **stack_a, int **stack_b, int top_a, int top_b);
void reverse_rotate_elems(int **stack, int top);
void reverse_rotate_both(int **stack_a, int **stack_b, int top_a, int top_b);

#endif
