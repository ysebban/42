/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:37:16 by ysebban           #+#    #+#             */
/*   Updated: 2022/11/26 19:27:24 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
int	main()
{
	long long a = 16;
	long long b = -2147483648;
	long long c = -9223372036854775807;
	long long d = 9223372036854775807;
	
	ft_printf(" %p ", 16);
	printf(" %p ", 16);
return (0);
}