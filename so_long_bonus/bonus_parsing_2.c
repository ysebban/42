/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:44:28 by ysebban           #+#    #+#             */
/*   Updated: 2023/03/09 13:44:30 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_fill(char **map, int x, int y, t_so_long *so_long)
{
	if (x < 0 || y < 0 || x >= ft_strlen(map [0]) || y >= ft_2dlen(map))
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E')
		so_long->fl_fill += 1;
	map[y][x] = 'X';
	f_fill(map, x - 1, y, so_long);
	f_fill(map, x + 1, y, so_long);
	f_fill(map, x, y - 1, so_long);
	f_fill(map, x, y + 1, so_long);
}

int	flood_fill(t_so_long *so_long)
{
	int		x;
	int		y;
	int		i;
	char	**map;

	i = 0;
	map = ft_calloc(sizeof(char *), ft_2dlen(so_long->map));
	while (so_long->map[i])
	{	
		map[i] = ft_strdup(so_long->map[i]);
		i ++;
	}
	x = so_long->player.pos.x;
	y = so_long->player.pos.y;
	f_fill(map, x, y, so_long);
	i--;
	while (i >= 0)
	{
		free(map[i]);
		i--;
	}
	free(map);
	if (so_long->fl_fill == (lstsize(so_long -> all_coin.all) + 1))
		return (1);
	return (0);
}
int	ft_2dlen(char **str)
{
	int	res;

	res = 0;
	while (str[res])
		res ++;
	return (res);
}

int	check_entry(char **data_map)
{
	int	i;

	i = 0;
	while (data_map[i])
	{
		if (entry_is_legit(data_map[i]) == 1)
			return (print_entry());
		i++;
	}
	return (0);
}

int	entry_is_legit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P'
			|| str[i] == 'C'
			|| str[i] == 'E'
			|| str[i] == '0'
			|| str[i] == '1'
			|| str[i] == 'B')
			i++;
		else
			return (1);
	}
	return (0);
}
