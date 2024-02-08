/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_load_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:47:18 by ysebban           #+#    #+#             */
/*   Updated: 2023/03/10 11:47:20 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
 
 #include "so_long.h"


void	init_all_mlx(t_so_long *so_long)
{
	int	x;
	int	y;

	y = ft_2dlen(so_long->map);
	x = ft_strlen(so_long->map[y - 1]);
	so_long -> mlx = mlx_init();
	so_long -> window = mlx_new_window(so_long->mlx, x * 32, y * 32, "SO_LONG");
	init_map_images(so_long);
	init_all_images(so_long);
	mlx_hook(so_long -> window, 2, 1l << 0, press, so_long);
	mlx_key_hook(so_long -> window, relase, so_long);
	mlx_hook(so_long -> window, 17, 1L << 17, end_clean, so_long);
	mlx_loop_hook(so_long->mlx, render_frame, so_long);
	mlx_loop(so_long->mlx);
}

int	render_frame(t_so_long *so_long)
{
	render_map(so_long);
	//get_coin_lision(so_long);
	render_else(so_long);
	//get_coin_lision(so_long);
	check_end(so_long);
	//print_moves(so_long, i);
	return (0);
}

void	render_map(t_so_long *so_long)
{
	int		x;
	int		y;

	y = 0;
	while (so_long -> map[y])
	{
		x = 0;
		while (so_long->map[y][x])
		{
			if (so_long->map[y][x] == '1')
			{
				if (find_wich_wall(so_long->map, x, y) == 1)
					mlx_put_image_to_window(so_long->mlx, so_long->window,
						so_long->images.wall_1, x * 32, y * 32);
				else
					mlx_put_image_to_window(so_long->mlx, so_long->window,
						so_long->images.wall_2, x * 32, y * 32);
			}
			else
				mlx_put_image_to_window(so_long->mlx, so_long->window,
					so_long->images.back, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	render_else(t_so_long *so_long)
{
	static int i;
	
	get_coin_lision(so_long);
	render_coin(so_long);
	mlx_put_image_to_window(so_long->mlx, so_long->window, so_long->exit.image,
		so_long->exit.pos.x * 32, so_long->exit.pos.y * 32);
	//render_player(so_long);
	gravity(so_long, i);
	if (i%3 == 0)
		get_player_new_pos(so_long, i);
	if (i > 99)
		i = 0;
	if (get_next_tile(so_long, so_long->player.pos, BOTTOM) == '1')
		so_long->player.jump = 0;
	if (get_next_tile(so_long, so_long->player.pos, BOTTOM) == '1' && so_long->player.flying_count >= 0 && i%3 == 0)
		so_long->player.flying_count --;
	i++;
}

void	render_coin(t_so_long *so_long)
{
	t_coin	*keep_head;

	keep_head = so_long->all_coin.all;
	while (so_long->all_coin.all)
	{
		if (so_long->all_coin.all->state == 1)
		{	
			mlx_put_image_to_window(so_long->mlx, so_long->window,
				so_long->all_coin.all->image, so_long->all_coin.all->pos.x * 32,
				so_long->all_coin.all->pos.y * 32);
		}
		else
			mlx_put_image_to_window(so_long->mlx, so_long->window,
				so_long->images.back, so_long->all_coin.all->pos.x * 32,
				so_long->all_coin.all->pos.y * 32);
		so_long->all_coin.all = so_long->all_coin.all->next;
	}
	so_long->all_coin.all = keep_head;
}


