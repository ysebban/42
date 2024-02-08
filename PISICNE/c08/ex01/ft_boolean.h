/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 17:11:19 by ysebban           #+#    #+#             */
/*   Updated: 2022/10/06 14:53:16 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H

# define FT_BOOLEAN_H

# include "unistd.h"

# define EVEN(x) x % 2 == 0

# define TRUE 0

# define FALSE 1

# define EVEN_MSG "I have an even numbers of arguments\n"

# define ODD_MSG "I have an odd numbers of arguments\n"

# define SUCCESS 0

typedef char	t_bool;
#endif
