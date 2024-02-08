/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:25:26 by ysebban           #+#    #+#             */
/*   Updated: 2023/03/08 16:25:28 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_that_done(char c, int p, int cc, int e)
{
	if (c == 'P')
		p++;
	if (c == 'C')
		cc++;
	if (c == 'E')
		e++;
}

int	check_assets(char **data_map, int i, int ii)
{
	int	c;
	int	p;
	int	e;

	c = 0;
	p = 0;
	e = 0;
	while (data_map[++i])
	{
		ii = 0;
		while (data_map[i][++ii])
		{
			if (data_map[i][ii] == 'P')
				p++;
			if (data_map[i][ii] == 'C')
				c++;
			if (data_map[i][ii] == 'E')
				e++;
		}
	}
	if (c == 0 || p != 1 || e != 1)
		return (print_asset());
	return (0);
}

int	lstsize(t_coin *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	end_clean(t_so_long *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->window);
	exit (0);
}
