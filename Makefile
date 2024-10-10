SRC = push_swap.c push_swap_utils.c push_swap_utils2.c push_swap_utils3.c operation.c operation2.c operation3.c list_utils.c Error.c algo.c algo2.c algo3.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
PRINTF_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	$(CC) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	rm -f $(OBJ)
	rm -f *~

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	rm -f $(NAME)

re: fclean all
