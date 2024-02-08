/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_chara.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:51:30 by ysebban           #+#    #+#             */
/*   Updated: 2023/03/09 13:51:33 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	gravity(t_so_long *so_long, int i)
{
	if (so_long->player.jump <= 0 && get_next_tile(so_long, so_long->player.pos, BOTTOM) != '1' && i%2 == 0)
	{
		if (so_long->player.left > 0 && get_next_tile(so_long, so_long->player.pos, B_L) != '1')
			so_long->player.pos.x -= 1;
		if (so_long->player.rigth > 0 && get_next_tile(so_long, so_long->player.pos, B_R) != '1')
			so_long->player.pos.x += 1;
		so_long->player.pos.y += 1;
		so_long->player.jump = -1;
	}
	else 
	so_long->player.pos.y = so_long->player.pos.y;
	so_long->player.pos.x = so_long->player.pos.x;
}

int	press(int key_code, t_so_long *so_long)
{
	if ((key_code == 126 || key_code == 13 || key_code == 49) && so_long->player.flying_count < so_long->player.max_air_frame)
		so_long->player.jump = 1;
	if (key_code == 53)
		end_clean(so_long);
	if ((key_code == 124 || key_code == 2) && get_next_tile(so_long, so_long->player.pos, RIGTH) != '1')
		so_long->player.rigth = 1;
	if ((key_code == 123 || key_code == 0 ) && get_next_tile(so_long, so_long->player.pos, LEFT) != '1')
		so_long->player.left = 1;
	return (0);
}

int relase(int key_code, t_so_long *so_long)
{
	if (key_code == 124 || key_code == 2)
		so_long->player.rigth = 0;
	if (key_code == 123 || key_code == 0)
		so_long->player.left = 0;
	if (key_code == 126 || key_code == 13 || key_code == 49)
		so_long->player.jump = 0;
	return (0);
}
