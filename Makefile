# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 13:28:10 by thi-nguy          #+#    #+#              #
#    Updated: 2020/09/22 11:29:26 by thi-nguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -lmlx -lm -framework OpenGL -framework AppKit

FLAGS = -g -Wall -Wextra -Werror -I.

CC = gcc

NAME = cub3D

SRC = main.c config/*.c gnl/*.c libft/*.c

all: $(NAME)

$(NAME):
	 $(CC) $(FLAGS) $(SRC) -Imlx $(MLX) -o $(NAME) 

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re: fclean all


