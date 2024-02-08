/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:50:55 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/22 01:28:09 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_even(void)
{
	red();
	ft_printf("The map isn't even\n");
	reset_col();
	ft_printf("all lines must be the same length\n");
	return (1);
}

int	print_shape(void)
{
	red();
	ft_printf("YOU MADE A SQUARE --'... \n");
	reset_col();
	ft_printf("Please enter a rectangle\n");
	return (1);
}

int	print_edges(void)
{
	red();
	ft_printf("Edges aren't walls, there's no void in my game\n");
	reset_col();
	ft_printf("ALL EDGES SHALL BE '1'\n");
	return (1);
}

int	print_asset(void)
{
	red();
	ft_printf("Wrong display with your arguments\n");
	reset_col();
	ft_printf("only 1 player, at least 1 exit and 1 collectible\n");
	return (1);
}

int	print_entry(void)
{
	red();
	ft_printf("Unsupported character detected\n");
	reset_col();
	ft_printf("Are now supported\n0 : 1 : C : P : E\n");
	return (1);
}
