SRC = push_swap.c operation.c operation2.c utils_list.c Error.c algo.c algo2.c algo3.c utils_update.c utils_update2.c utils.c
OBJ = $(SRC:.c=.o)
NAME = push_swap
CC = gcc -g -fsanitize=address
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
