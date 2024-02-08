/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 10:58:21 by ysebban           #+#    #+#             */
/*   Updated: 2023/03/21 10:58:24 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	get_player_new_pos(t_so_long *so_long, int i)
{
	if (so_long->player.jump > 0)
		get_player_while_jump(so_long);
	if (so_long->player.left > 0 && get_next_tile(so_long, so_long->player.pos, LEFT) != '1')
		so_long->player.pos.x -= 1;
	if (so_long->player.rigth > 0 && get_next_tile(so_long, so_long->player.pos, RIGTH) != '1')
		so_long->player.pos.x += 1;
	if (get_next_tile(so_long, so_long->player.pos, RIGTH) == '1')
		so_long->player.rigth = 0;
	if (get_next_tile(so_long, so_long->player.pos, LEFT) == '1')
		so_long->player.left = 0;
	print_moves(so_long, i);
}

void	print_trail(t_so_long *so_long)
{
	void	*trail_image;
	int x = so_long->player.pos.x;
	int y= so_long->player.pos.y;
	int width, height;
	// if(so_long->player.flying_count <= (so_long->player.max_air_frame /3))
	// 	print_sacades;
	if (get_next_tile(so_long, so_long->player.pos, BOTTOM) != '1')
	{
		trail_image = mlx_xpm_file_to_image(so_long->mlx,
				"./assets/chara/trail/flying_trail_0.xpm",
				&width, &height);
		y += 2;
		mlx_put_image_to_window(so_long->mlx, so_long->window, trail_image, x*32, y*32);
	}

}

void	get_player_while_jump(t_so_long *so_long)
{
		if (so_long->player.flying_count == so_long->player.max_air_frame)
		{
			so_long->player.jump = 0;
			return;
		}
		if (get_next_tile(so_long, so_long->player.pos, TOP) == '1')
			so_long->player.pos.y = so_long->player.pos.y;
		if (get_next_tile(so_long, so_long->player.pos, RIGTH) != '1')
			so_long->player.pos.x += 1;
		if (get_next_tile(so_long, so_long->player.pos, LEFT) != '1')
			so_long->player.pos.x -= 1;
		if (get_next_tile(so_long, so_long->player.pos, TOP) != '1')
			so_long->player.pos.y -= 1;
		so_long->player.flying_count ++;
		print_trail(so_long);
}

