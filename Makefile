# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rugrigor <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 14:08:11 by rugrigor          #+#    #+#              #
#    Updated: 2023/03/22 12:12:12 by rugrigor         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

SRC = 	so_long.c			\
		map.c				\
		errors.c			\
		grafic.c			\
		control.c			\
		move_fill.c			\
		logic.c				\
		utils/ft_strlen.c	\
		utils/ft_strtrim.c	\
		utils/ft_strdup.c	\
		utils/ft_strstr.c	\
		utils/ft_memset.c	\
		utils/ft_split.c	\
		utils/ft_substr.c	\
		utils/ft_itoa.c		\

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -Imlx $< -o $@

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJ)

re: fclean all

.PHONY: all clean fclean re
