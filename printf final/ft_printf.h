/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysebban <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:51:17 by ysebban           #+#    #+#             */
/*   Updated: 2022/12/19 14:45:32 by ysebban          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include "stdlib.h"
# include "stddef.h"
# include "stdarg.h"

int	ft_printf(const char *str, ...);
int	sort_type(va_list a_voir, char c);
int	my_putnbr_base(unsigned int nbr, char *base);
int	my_unsigned_putnbr(unsigned int nb);
int	my_putchar(char c);
int	my_putstr(char *str);
int	my_putnbr(int nb);
int	my_put_p(unsigned long long nbr, char *base);
int	useless(unsigned long long nbr);
void red(void);
void green(void);
void yellow(void);
void blue(void);
void purple(void);
void cyan(void);
void reset_col(void);
#endif
