/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:40:09 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:40:10 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_char_left(t_style *style, int i)
{
	write(1, &i, 1);
	style->count++;
	while (style->width > 1)
	{
		if (style->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		style->width--;
		style->count++;
	}
}

static void	ft_char_right(t_style *style, int i)
{
	while (style->width > 1)
	{
		if (style->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		style->width--;
		style->count++;
	}
	write(1, &i, 1);
	style->count++;
}

void		ft_char(char c, t_style *style, va_list vlist)
{
	if (c == 'C' || style->l == 1)
		ft_uchar(style, va_arg(vlist, int));
	else if (style->minus == 1)
		ft_char_left(style, va_arg(vlist, int));
	else
		ft_char_right(style, va_arg(vlist, int));
}
