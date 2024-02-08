/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:26:16 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/17 05:26:36 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_player(t_so_long *so_long)
{
	static int	anim_index;
	void		*image;

	ft_printf("\n\n\n\n\n .  %d .  \n", anim_index);
	if (so_long->player.jump == 1)
		image = so_long->player.anim_f.all_images[0];
	if (so_long->player.jump == -1)
		image = so_long->player.anim_f.all_images[1];
	if (so_long->player.left > 0)
	{
		image = so_long->player.anim_l.all_images[anim_index];
		if (anim_index == so_long->player.anim_l.len)
			anim_index = 0;
	}
	if (so_long->player.rigth > 0)
	{
		image = so_long->player.anim_r.all_images[anim_index];
		if (anim_index == so_long->player.anim_r.len)
			anim_index = 0;
	}
		mlx_put_image_to_window(so_long->mlx, so_long->window, image, so_long->player.pos.x*32, so_long->player.pos.y *32);
}