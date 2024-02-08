/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:29:35 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/19 18:08:49 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;
	int	k;

	i = 0;
	k = ft_strlen(s);
	if (!s)
		s = 0;
	while (i < k)
	{	
		(*f)(i, s);
		i ++;
		s ++;
	}
}
