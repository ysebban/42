/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:46:01 by ysebban           #+#    #+#             */
/*   Updated: 2023/04/04 17:46:03 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_anim init_fly_anim(t_so_long *so_long)
{
	t_anim	anim;
	void	*all_images[2];
	int		len;

	len = 2;
	all_images[0]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Fly/player_fly_down_0.xpm", &so_long->w, &so_long->h);
	all_images[1] = mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Fly/player_fly_up_0.xpm", &so_long->w, &so_long->h);
	anim.all_images = all_images;
	anim.len = len;
	return (anim);
}

t_anim init_left_anim(t_so_long *so_long)
{
	t_anim	anim;
	void	*all_images[7];
	int		len;

	len = 7;
	all_images[0]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_Left/player_run_left_0.xpm", &so_long->w, &so_long->h);
	all_images[1]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_Left/player_run_left_1.xpm", &so_long->w, &so_long->h);
	all_images[2]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_Left/player_run_left_2.xpm", &so_long->w, &so_long->h);
	all_images[3]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_Left/player_run_left_3.xpm", &so_long->w, &so_long->h);
	all_images[4]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_Left/player_run_left_4.xpm", &so_long->w, &so_long->h);
	all_images[5]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_Left/player_run_left_5.xpm", &so_long->w, &so_long->h);
	all_images[6]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_Left/player_run_left_6.xpm", &so_long->w, &so_long->h);
	anim.all_images = all_images;
	anim.len = len;
	return (anim);
}
t_anim init_rigth_anim(t_so_long *so_long)
{
	t_anim	anim;
	void	*all_images[7];
	int		len;

	len = 7;
	all_images[0]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_rigth/player_run_rigth_0.xpm", &so_long->w, &so_long->h);
	all_images[1]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_rigth/player_run_rigth_1.xpm", &so_long->w, &so_long->h);
	all_images[2]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_rigth/player_run_rigth_2.xpm", &so_long->w, &so_long->h);
	all_images[3]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_rigth/player_run_rigth_3.xpm", &so_long->w, &so_long->h);
	all_images[4]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_rigth/player_run_rigth_4.xpm", &so_long->w, &so_long->h);
	all_images[5]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_rigth/player_run_rigth_5.xpm", &so_long->w, &so_long->h);
	all_images[6]= mlx_xpm_file_to_image(so_long->mlx, "./assets/Chara/Walk_rigth/player_run_rigth_6.xpm", &so_long->w, &so_long->h);
	anim.all_images = all_images;
	anim.len = len;
	return (anim);
}
void	init_all_images(t_so_long *so_long)
{
	//so_long->player.anim_h = init_hurt_anim(so_long);
	//so_long->player.anim_a = init_attack_anim(so_long);
	so_long->player.anim_f = init_fly_anim(so_long);
	so_long->player.anim_l = init_left_anim(so_long);
	so_long->player.anim_r = init_rigth_anim(so_long);
}
