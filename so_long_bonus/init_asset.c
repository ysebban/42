/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 13:25:18 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/26 13:25:19 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_so_long *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (so_long -> map[y])
	{
		x = 0;
		while (so_long -> map[y][x])
		{
			if (so_long -> map[y][x] == 'P')
			{
				so_long -> player.pos.x = x;
				so_long -> player.pos.y = y;
				so_long ->player.dir.y = 0;
				so_long->player.dir.x = 0;
				so_long ->player.moves = 0;
				so_long->player.jump = 0;
				so_long->player.rigth = 0;
				so_long->player.left = 0;
				so_long->player.flying_count = 0;
				so_long->player.max_air_frame = 50;
			}
			x ++;
		}
		y ++;
	}
}

void	init_exit(t_so_long *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (so_long -> map[y])
	{
		x = 0;
		while (so_long -> map[y][x])
		{
			if (so_long -> map[y][x] == 'E')
			{
				so_long -> exit.pos.x = x;
				so_long -> exit.pos.y = y;
			}
			x ++;
		}
		y ++;
	}
}

void	init_all_coin(t_so_long *so_long)
{
	int	x;
	int	y;

	y = 0;
	while (so_long -> map[y])
	{
		x = 0;
		while (so_long -> map[y][x])
		{
			if (so_long -> map[y][x] == 'C')
				so_long -> all_coin.all = add_coin(so_long->all_coin.all, x, y);
			x ++;
		}
		y ++;
	}
}

t_coin	*init_coin_image(t_so_long *so_long, int width, int height)
{
	t_coin	*head;

	head = so_long->all_coin.all;
	while (so_long->all_coin.all)
	{
		so_long->all_coin.all->image
			= mlx_xpm_file_to_image(so_long->mlx,
				"./assets/coin/coin.0.xpm",
				&width, &height);
		so_long->all_coin.all = so_long->all_coin.all->next;
	}
	return (head);
}

void	init_map_images(t_so_long *so_long)
{
	int	width;
	int	height;

	so_long->images.wall_1 = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/WALL/wall1.1.xpm", &width, &height);
	so_long->images.wall_2 = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/WALL/WALL_2.2.xpm", &width, &height);
	so_long->images.back = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/WALL/dark_sky_background.xpm", &width, &height);
	so_long->exit.image = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/Door/hole.xpm", &width, &height);
	so_long->all_coin.all = init_coin_image(so_long, width, height);
	so_long->player.image = mlx_xpm_file_to_image(so_long->mlx,
			"./assets/Chara/chara.00.xpm", &width, &height);
}
