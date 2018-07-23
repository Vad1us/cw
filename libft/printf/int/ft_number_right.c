/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 18:52:29 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/24 18:52:33 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_nozero(t_style *style)
{
	while (style->width > 0)
	{
		write(1, " ", 1);
		style->count++;
		style->width--;
	}
}

static void	ft_part2(long long i, t_style *style)
{
	char *str;

	str = ft_itoa(i);
	while (style->width > 0)
	{
		write(1, "0", 1);
		style->count++;
		style->width--;
	}
	while (style->acc > 0)
	{
		write(1, "0", 1);
		style->count++;
		style->acc--;
	}
	if (!(style->flag == 1 && style->true_acc == 0 && ft_strcmp(str, "0") == 0))
	{
		ft_putstr(str);
		style->count += ft_strlen(str);
	}
	free(str);
}

void		ft_number_right(t_style *style, long long i)
{
	if (style->h == 1)
		i = (short)i;
	if (style->hh == 1)
		i = (signed char)i;
	if (style->space == 1)
	{
		write(1, " ", 1);
		style->count++;
	}
	if (style->zero != 1)
		ft_nozero(style);
	if (i >= 0 && style->plus == 1)
	{
		write(1, "+", 1);
		style->count++;
	}
	if (i < 0)
	{
		write(1, "-", 1);
		style->count++;
		i = -i;
	}
	ft_part2(i, style);
}
