/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:01:25 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/17 16:01:25 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_left(t_style *style, char c)
{
	write(1, &c, 1);
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

static void	ft_right(t_style *style, char c)
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
	write(1, &c, 1);
	style->count++;
}

void		ft_invalid(char *f, t_style *style)
{
	if (style->minus == 0)
		ft_right(style, *f);
	else
		ft_left(style, *f);
}
