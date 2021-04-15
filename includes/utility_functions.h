/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utility_functions.h                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/12 17:05:58 by tuperera      #+#    #+#                 */
/*   Updated: 2021/04/15 12:13:56 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_FUNCTIONS_H
# define UTILITY_FUNCTIONS_H
# include <stdio.h>
# include <stdint.h>
# include "../libft/libft.h"
# include "../includes/stack.h"
# define STDIN 0
# define STDOUT 1
# define STACK_A 2
# define STACK_B 3
# define MIN_ARRAY_SIZE 10

int 	number_of_sorted_values(int *stack, int size);
int		is_sorted_ascending(int *stack, int size);
int 	is_sorted_descending(int *stack, int size);
int		*reallocate_array(int **array, int size, int realloc_amount);
int		push_args_to_stack(int **stack_a, int *top, char **argument_list, int argument_count);
int		is_in(int *stack, int top, int num);
void	print_stack(int *stack_a, int *stack_b, int top_a, int top_b);
void	reverse_elements_in_array(int **array, int size);
int		exit_error(char *str);

#endif
