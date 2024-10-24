# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yass <yass@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 21:28:30 by yass              #+#    #+#              #
#    Updated: 2024/02/06 21:28:31 by yass             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SOURCES	=	prints.c	prints2.c	ft_printf.c	
OBJS	=	$(SOURCES:.c=.o)
CC	=	gcc
CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
	$(AR) -rcs $(NAME) $(OBJS)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all