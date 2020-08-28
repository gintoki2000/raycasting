
MLX = -lmlx -lm -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

CC = gcc

NAME = cub3D

SRC = ./*.c

$(NAME):
	 $(CC) $(FLAGS) $(SRC) -Imlx $(MLX) -o $(NAME) 

run:
	./$(NAME)

fclean :
	rm -rf $(NAME)

