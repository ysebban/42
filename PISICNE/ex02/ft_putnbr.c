/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:11:46 by ysebban           #+#    #+#             */
/*   Updated: 2022/09/27 12:05:39 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		write (1, "2147483648", 10);
		return ;
	}	
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}	
	if (nb > 9)
	{
		ft_putnbr (nb / 10);
		ft_putnbr (nb % 10);
	}
	if (nb <= 9)
		ft_putchar(nb + 48);
}
/*
int main(void)
{
	ft_putnbr(-89456);
	return (0);
}
*/
