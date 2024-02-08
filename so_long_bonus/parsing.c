/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:04:12 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/22 02:15:24 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **data_map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	if (check_entry(data_map) == 1)
		i = 1;
	if (check_even(data_map) == 1)
		i = 1;
	if (check_shape(data_map) == 1)
		i = 1;
	if (check_edges(data_map) == 1)
		i = 1;
	if (check_assets(data_map, j, k) == 1)
		i = 1;
	return (i);
}

int	check_even(char **data_map)
{
	int	first_len;
	int	len;
	int	i;

	i = 1;
	first_len = ft_strlen((const char *)data_map[0]);
	while (data_map[i])
	{
		len = ft_strlen((const char *)data_map[i]);
		if (len != first_len)
			return (print_even());
		i ++;
	}
	return (0);
}

int	check_shape(char **data_map)
{
	if (ft_strlen((const char *)data_map[0]) == (ft_2dlen(data_map)))
		return (print_shape());
	else
		return (0);
}

int	check_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
		{	
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_edges(char **data_map)
{
	int	len_max;
	int	end_string;
	int	i;
	int	ii;

	i = 1;
	len_max = ft_2dlen(data_map);
	end_string = ft_strlen((const char *)data_map[i]);
	if (check_walls(data_map[0]) != 0)
		return (print_edges());
	if (check_walls(data_map[len_max -1]) != 0)
		return (print_edges());
	while (data_map[i])
	{
		ii = 0;
		while (data_map[i][ii])
		{
			if (data_map[i][0] != '1' || data_map[i][end_string -1] != '1')
				return (print_edges());
			ii++;
		}
		i ++;
	}
	return (0);
}
