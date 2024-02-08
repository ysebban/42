/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:22:54 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/24 04:24:24 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_wich_wall(char **data_map, int x, int y)
{
	if (x == 0 || y == 0)
		return (2);
	if (x == ft_strlen(data_map[y]))
		return (2);
	if (data_map[y - 1][x] == '1')
		return (2);
	else
		return (1);
}

t_coin	*add_coin(t_coin *coin, int x, int y)
{
	t_coin	*new_coin;

	new_coin = malloc(sizeof(t_coin));
	new_coin->state = 1;
	new_coin->pos.x = x;
	new_coin->pos.y = y;
	new_coin->next = NULL;
	add_all_coin(&coin, new_coin);
	return (coin);
}

void	add_all_coin(t_coin **lst, t_coin *new)
{
	t_coin	*last;

	last = (*lst);
	if (lst)
	{
		if (*lst)
		{
			last = coin_last(*lst);
			last -> next = new;
		}
		else
		*lst = new;
	}
}

t_coin	*coin_last(t_coin *lst)
{
	if (lst -> next == NULL)
		return (lst);
	while (lst)
	{
		if (lst -> next == NULL)
			return (lst);
		lst = lst -> next;
	}
	return (lst);
}

void	print_moves(t_so_long *so_long)
{
	system("clear");
	ft_printf("COUNT MOVES:");
	yellow();
	ft_printf("%d\n", so_long->player.moves);
	reset_col();
}
