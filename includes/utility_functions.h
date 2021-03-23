/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility_functions.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 17:05:58 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/23 10:52:08 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_FUNCTIONS_H
# define UTILITY_FUNCTIONS_H
# define STDIN 0
# define STDOUT 1

int		*reallocate_array(int **array, int size);
int		push_args_to_stack(int **stack_a, int *top, char **argument_list, int argument_count);
int		is_in(int *stack, int top, int num);
void	print_stack(int *stack_a, int *stack_b, int top_a, int top_b);
void	reverse_elements_in_array(int **array, int size);
int		exit_error(char *str);

#endif
