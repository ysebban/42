/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:05:19 by ysebban           #+#    #+#             */
/*   Updated: 2023/03/01 12:05:22 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_clean(t_so_long *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->window);
	//system("leaks so_long");
	exit (0);
}

void	print_moves(t_so_long *so_long , int i)
{
	//system("clear");
	// ft_printf("COUNT MOVES:");
	// yellow();
	// ft_printf("%d\n", so_long->player.moves);
	// reset_col();
	ft_printf("\n left = %d \n rigth = %d \n Jump = %d\n", so_long->player.left, so_long->player.rigth, so_long->player.jump);
	ft_printf(" I val = %d \n", i);
	ft_printf(" Flying val = %d \n", so_long->player.flying_count);
}
