NAME = push_swap

SRC = push_swap_lst.c push_swap.c push_swap_ops.c\
	push_swap_utils.c push_swap_list_comp.c push_swap_optmization.c\
	push_swap_list_data.c  push_swap_sort2.c push_swap_sort3.c

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJS = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): $(SUBDIRS) $(OBJS)

clean:
	rm -f $(OBJS) $(BNS_OBJS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY: clean fclean libft