SRC = 	so_long.c \
		print_map_error.c \
		parsing.c parsing_2.c parsing_3.c \
		load_map.c utils.c  utils_2.c chara.c init_asset.c collisions.c
OBJ = $(SRC:.c=.o)

SRC_BONUS = parsing.c bonus_parsing_2.c parsing_3.c utils_2.c utils.c \
			print_map_error.c collisions.c \
			bonus_load_map.c bonus_chara.c init_asset.c so_long.c get_player_pos.c \
			init_images_bonus.c cmd.c
OBJ_BONUS = $(SRC_BONUS:.c=.o)



CC = gcc

CFLAGS = -g -Wall -Wextra -Werror

NAME = so_long

NAME_BONUS = so_long_bonus

all : $(NAME)
$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft -lmlx -framework OpenGL -framework AppKit

bonus : $(NAME_BONUS)
$(NAME_BONUS): $(OBJ_BONUS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS) -Llibft -lft -lmlx -framework OpenGL -framework AppKit

clean:
	make clean -C libft
	rm -f $(OBJ) $(OBJ_BONUS)

fclean : clean
	make fclean -C libft
	rm -f $(NAME) $(NAME_BONUS)

re : fclean all
