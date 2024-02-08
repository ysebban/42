/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chara.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:25:23 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/24 04:24:16 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_collisions_up(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player.pos.x;
	y = so_long->player.pos.y;
	if (so_long->map[y - 1][x] != '1' && (so_long->map[y - 1][x] != 'E'
		|| (so_long->all_coin.count == lstsize(so_long->all_coin.all)
		&& so_long->map[y - 1][x] == 'E')))
	{
		so_long->player.pos.y -= 1;
		so_long->player.moves ++;
		print_moves(so_long);
	}
}

void	check_collisions_down(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player.pos.x;
	y = so_long->player.pos.y;
	if (so_long->map[y + 1][x] != '1'
		&& (so_long->map[y + 1][x] != 'E'
		|| (so_long->all_coin.count == lstsize(so_long->all_coin.all)
		&& so_long->map[y + 1][x] == 'E')))
	{	
		so_long->player.pos.y += 1;
		so_long->player.moves ++ ;
		print_moves(so_long);
	}
}

void	check_collisions_left(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player.pos.x;
	y = so_long->player.pos.y;
	if (so_long->map[y][x + 1] != '1'
		&& (so_long->map[y][x + 1] != 'E'
		|| (so_long->all_coin.count == lstsize(so_long->all_coin.all)
		&& so_long->map[y][x + 1] == 'E')))
	{
		so_long->player.pos.x += 1;
		so_long->player.moves ++;
		print_moves(so_long);
	}
}

void	check_collisions_rigth(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player.pos.x;
	y = so_long->player.pos.y;
	if (so_long->map[y][x + 1] == 'E')
		check_end(so_long);
	if (so_long->map[y][x - 1] != '1'
	&& (so_long->map[y][x - 1] != 'E'
	|| (so_long->all_coin.count == lstsize(so_long->all_coin.all)
	&& so_long->map[y][x - 1] == 'E')))
	{	
		so_long->player.pos.x -= 1;
		so_long->player.moves ++;
		print_moves(so_long);
	}
}

int	get_moves(int key_code, t_so_long *so_long)
{
	if (key_code == 53)
		end_clean(so_long);
	if (key_code == 126 || key_code == 13)
		check_collisions_up(so_long);
	if (key_code == 125 || key_code == 1)
		check_collisions_down(so_long);
	if (key_code == 124 || key_code == 2)
		check_collisions_left(so_long);
	if (key_code == 123 || key_code == 0)
		check_collisions_rigth(so_long);
	return (0);
}
