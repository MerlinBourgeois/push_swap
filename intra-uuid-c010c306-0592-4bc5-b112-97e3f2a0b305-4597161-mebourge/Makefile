# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mebourge <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 16:41:58 by mebourge          #+#    #+#              #
#    Updated: 2022/12/15 15:10:17 by mebourge         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
		push_swap2.c \
		operate.c \
		operate2.c \
		operate3.c \
		radix.c

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Werror -Wextra -O2 -O3 -Os

LIB  = ar rcs $(NAME) ./includes/libft/libft.a

REMOVE = rm -f

DEPENDS = make -C includes/libft

COMPILE = gcc $(CFLAGS) -o $(NAME) -Iincludes -Lincludes/libft -lft

all: $(NAME)

libft:
	$(DEPENDS)

$(NAME): libft $(OBJ)
	@$(COMPILE) $(OBJ)

clean:
	@$(REMOVE) $(OBJ)
	make -C includes/libft clean

fclean:	clean
	@$(REMOVE) $(NAME)
	make -C includes/libft fclean

re: fclean all

.PHONY: all clean fclean re