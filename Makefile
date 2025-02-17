# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alel-you <alel-you@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 19:49:50 by alel-you          #+#    #+#              #
#    Updated: 2025/02/17 15:26:25 by alel-you         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = src/main.c src/parse_utils.c src/stack_op.c sort/big_sort.c sort/index.c sort/short_sort.c sort/sorting_utils.c \
	instructions/push.c instructions/rotate.c instructions/rrotate.c instructions/swap.c

OBJCTS = $(FILES:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = push_swap

all: $(NAME)

%.o: %.c includes/push_swap.h
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJCTS)
	@make -C ./libft
	@$(CC) $(FLAGS) $(OBJCTS) libft/libft.a -o $(NAME)

clean:
	@make -C ./libft clean
	@rm -rf $(OBJCTS)

fclean: clean
	@make -C ./libft fclean
	@rm -rf $(NAME)

re: fclean all

# last one