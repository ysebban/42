/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:24:19 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/27 18:24:21 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_coin_lision(t_so_long *so_long)
{
	t_coin	*current;

	current = so_long->all_coin.all;
	while (current)
	{
		if (so_long->player.pos.x == current->pos.x
			&& so_long->player.pos.y == current->pos.y
			&& current->state == 1)
		{	
			current->state = 0;
			so_long->all_coin.count ++;
		}
		current = current->next;
	}
}

void	check_end(t_so_long *so_long)
{
	int	x;
	int	y;

	x = so_long->player.pos.x;
	y = so_long->player.pos.y;
	if (so_long->all_coin.count == lstsize(so_long->all_coin.all)
		&& (so_long->map[y][x] == 'E'))
		end_clean(so_long);
}
