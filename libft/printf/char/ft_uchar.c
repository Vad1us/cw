/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 14:44:52 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/13 14:44:53 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_char_left(t_style *style, int i)
{
	ft_uni(i);
	style->count += ft_usize(i);
	while (style->width > 0)
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
	while (style->width > 0)
	{
		if (style->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		style->width--;
		style->count++;
	}
	ft_uni(i);
	style->count += ft_usize(i);
}

void		ft_uchar(t_style *style, int i)
{
	style->width -= ft_usize(i);
	if (style->minus == 1)
		ft_char_left(style, i);
	else
		ft_char_right(style, i);
}
