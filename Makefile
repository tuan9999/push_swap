# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tuperera <tuperera@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/03/08 16:36:40 by tuperera      #+#    #+#                  #
#    Updated: 2021/04/05 11:36:38 by tuperera      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

FLAGS = -Wall -Werror -Wextra

FILES = stack \
		push_instruction_set \
		swap_instruction_set \
		rotate_instruction_set \
		reverse_rotate_instruction_set \
		utility_functions \
		merge_sort

SRC = $(addprefix srcs/, $(addsuffix .c, $(FILES)))

INCLUDE = -I includes

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

GNL =	get_next_line \
		get_next_line_utils

GNL_SRC = $(addprefix get_next_line/, $(addsuffix .c, $(GNL)))

.PHONY: clean fclean re all bonus

all: $(NAME)
	gcc $(FLAGS) -o push_swap $(SRC) $(GNL_SRC) srcs/push_swap.c $(LIBFT)
	gcc $(FLAGS) -o checker $(SRC) $(GNL_SRC) srcs/checker.c $(LIBFT)

$(NAME): $(OBJS)
	cd libft && $(MAKE) all && $(MAKE) bonus

clean:
	@echo "Cleaning objects"
	@rm -f $(OBJ)

fclean: clean
	@echo "Removing executables"
	@rm -f $(NAME)
	@rm -f checker

re: fclean all
