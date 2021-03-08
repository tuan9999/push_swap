/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tuperera <tuperera@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 16:34:50 by tuperera      #+#    #+#                 */
/*   Updated: 2021/03/08 17:27:44 by tuperera      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "stack.h"
#include "libft.h"

int main(int argc, char **argv) {
	int *stack;
	int i;
	int top;
	
	i = argc - 1;
	top = 1;
	if (argc < 1) {
		ft_putstr_fd("Error\n", 1);
		return (-1);
	}
	stack = init_stack(argv[i]);
	while (i != 1) {
		i--;
		push(&stack, &top, argv[i]);
	}
}