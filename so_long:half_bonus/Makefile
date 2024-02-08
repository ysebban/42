SRC = 	so_long.c \
		print_map_error.c \
		parsing.c parsing_2.c parsing_3.c \
		load_map.c utils.c chara.c init_asset.c collisions.c
OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long

all : $(NAME)
$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C libft
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	make fclean -C libft
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all
