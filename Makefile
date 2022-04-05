# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayassin <ayassin@student.42abudhabi.ae>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 10:16:50 by ayassin           #+#    #+#              #
#    Updated: 2022/04/04 12:14:44 by ayassin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

SRC = push_swap_list.c push_swap.c push_swap_ops.c\
	push_swap_utils.c push_swap_list_comp.c push_swap_optmization.c\
	push_swap_list_data.c  push_swap_sort2.c push_swap_sort3.c

OBJDIR = push_swap_objects

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean all re