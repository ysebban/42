/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:11:36 by ysebban           #+#    #+#             */
/*   Updated: 2023/02/19 21:10:43 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;
	int	clue;

	i = 0;
	count = 0;
	clue = 0;
	while (s[i])
	{
		if (s[i] != c && clue == 0)
		{
			count ++;
			clue = 1;
		}
		else if (s[i] == c)
			clue = 0;
		i++;
	}
	return (count);
}

static char	*get_word(const char *src, int start, int end)
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_calloc((end - start + 1), sizeof(char));
	if (!dest || !src)
		return (NULL);
	while (start < end)
	{
		dest[i++] = src[start++];
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;
	int		j;
	int		clue;

	i = 0;
	j = 0;
	clue = -1;
	dest = ft_calloc((count_word(s, c) + 1), sizeof (char *));
	if (!dest || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && clue < 0)
			clue = i;
		else if ((s[i] == c || i == ft_strlen(s)) && clue >= 0)
		{
			dest[j] = get_word(s, clue, i);
			clue = -1;
			j ++;
		}
		i++;
	}
	dest[j++] = NULL;
	return (dest);
}
