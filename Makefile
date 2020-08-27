
MLX = -lmlx -lm -framework OpenGL -framework AppKit

HEADER = types.h

FLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = cub3D

SRC = ./*.c

$(NAME):
	 $(CC) $(FLAGS) $(SRC) -I $(HEADER) -Imlx $(MLX) -o $(NAME) 

run:
	./$(NAME)

fclean :
	rm -rf $(NAME)

