/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 05:22:10 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/25 12:13:29 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(char **av)
{
	int		fd;
	char	*tmp;
	char	*join;
	char	**split;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	tmp = ft_calloc(sizeof(char *), 1);
	join = ft_calloc(sizeof(char), ft_strlen(tmp));
	while (tmp)
	{
		join = my_strjoin(join, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	split = ft_split(join, '\n');
	free(join);
	return (split);
}

void	init_game(t_so_long *so_long)
{
	init_player(so_long);
	init_all_coin(so_long);
	init_exit(so_long);
	so_long ->fl_fill = 0;
}

int	main(int ac, char **av)
{
	t_so_long	so_long;
	int			i;

	i = 0;
	so_long.map = get_map(av);
	if (ac != 2 || so_long.map == NULL || check_map(so_long.map) != 0)
		return (0);
	init_game(&so_long);
	if (flood_fill(&so_long) == 0)
	{
		ft_printf("NO VALID PATH\n");
		return (0);
	}
	init_all_mlx(&so_long);
	return (1);
}
