/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:20:07 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/25 12:13:38 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <fcntl.h>

typedef enum tile
{
	TOP,
	BOTTOM,
	RIGTH,
	LEFT,
	T_L = 13,
	T_R = 14,
	B_R = 23,
	B_L = 24
} t_tile_data;

typedef enum moove
{
	BLANK,
	JUMP_MV,
	FALL_MV,
	L_MV,
	R_MV
} t_moove_data;

typedef struct s_anim
{
	void	**all_images;
	int		len;
}			t_anim;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_exit
{
	t_pos	pos;
	void	*image;
}			t_exit;

typedef struct s_coin
{
	t_pos			pos;
	int				state;
	void			*image;
	struct s_coin	*next;
}					t_coin;

typedef struct s_all_coin
{
	int		count;
	t_coin	*all;
}			t_all_coin;

typedef struct s_player
{
	void			*image;
	int				moves;
	t_pos			pos;
	t_pos			dir;
	t_anim			anim_l;
	t_anim			anim_r;
	t_anim			anim_h;
	t_anim			anim_f;
	t_anim			anim_a;
	int				jump;
	int				left;
	int				rigth;
	int				flying_count;
	int				max_air_frame;
	t_moove_data	previous_move;
	t_moove_data	current_move;
}			t_player;

typedef struct s_map
{
	void	*wall_1;
	void	*wall_2;
	void	*back;
}			t_map;

typedef struct s_so_long
{
	void		*mlx;
	void		*window;
	char		**map;
	int			fl_fill;
	int			h;
	int			w;
	t_map		images;
	t_player	player;
	t_exit		exit;
	t_all_coin	all_coin;
}				t_so_long;

//PRINT_MAP_ERROR
int		print_entry(void);
int		print_even(void);
int		print_shape(void);
int		print_edges(void);
int		print_asset(void);

//PARSING
int		check_map(char **data_map);
int		check_even(char **data_map);
int		check_shape(char **data_map);
int		check_edges(char **data_map);
int		check_wall(char *str);

//PARSING_2
int		flood_fill(t_so_long *so_long);
int		count_all_coin(t_so_long *so_long);
int		ft_2dlen(char **str);
int		check_entry(char **data_map);
int		entry_is_legit(char *str);

//PARSING 3
int		check_assets(char **data_map, int i, int ii);
int		lstsize(t_coin *lst);

//INIT_ASSET
void	init_player(t_so_long *so_long);
void	init_exit(t_so_long *so_long);
void	init_all_coin(t_so_long *so_long);
void	init_map_images(t_so_long *so_long);
void	destroy_images(t_so_long *so_long);

//UTILS
int		find_wich_wall(char **data_map, int x, int y);
t_coin	*add_coin(t_coin *coin, int x, int y);
void	add_all_coin(t_coin **lst, t_coin *new);
t_coin	*coin_last(t_coin *lst);
char	get_next_tile(t_so_long *so_long, t_pos pos, t_tile_data dest);
void	init_player_new_pos(t_player player);

//LOAD_MAP
void	init_all_mlx(t_so_long *so_long);
int		render_frame(t_so_long *so_long);
void	render_map(t_so_long *so_long);
void	render_coin(t_so_long *so_long);
void	render_else(t_so_long *so_long);

//CHARA
void	check_collisions_up(t_so_long *so_long);
void	check_collisions_down(t_so_long *so_long);
void	check_collisions_left(t_so_long *so_long);
void	check_collisions_rigth(t_so_long *so_long);
int		get_moves(int key_code, t_so_long *so_long);

//utils_2
int		end_clean(t_so_long *so_long);
void	print_moves(t_so_long *so_long, int i);

//COLLISIONS
void	get_coin_lision(t_so_long *so_long);
void	check_end(t_so_long *so_long);

//CMD(RENDER_ANIM_BNS)
void	render_player(t_so_long *so_long);


//BONUS_CHARA
void	gravity(t_so_long *so_long, int i);
int		press(int key_code, t_so_long *so_long);
int		relase(int key_code, t_so_long *so_long);
void	get_player_dir(t_so_long *so_long);

//init_images_bonus

t_anim init_fly_anim(t_so_long *so_long);
t_anim init_left_anim(t_so_long *so_long);
t_anim init_rigth_anim(t_so_long *so_long);
void	init_all_images(t_so_long *so_long);


void	get_player_new_pos(t_so_long *so_long, int i);
void	moove_diago(t_so_long *so_long, t_pos p_pos, t_pos p_dir, int i);
void	moove_regular(t_so_long *so_long, t_pos p_pos, t_pos p_dir, int i);
void	get_player_while_jump(t_so_long *so_long);
#endif