/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:36:36 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/22 15:37:06 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_size(long long i)
{
	int					size;
	unsigned long long	i2;

	size = 1;
	if (i < 0)
		i2 = -i;
	else
		i2 = i;
	while (i2 >= 10)
	{
		i2 = i2 / 10;
		size++;
	}
	return (size);
}

static void	ft_number2(t_style *style, long long i)
{
	if (style->h == 1)
		i = (short)i;
	if (style->hh == 1)
		i = (signed char)i;
	if (style->acc != 0 || style->minus == 1)
		style->zero = 0;
	if (i < 0 && style->plus == 1)
		style->plus = 0;
	if (style->flag == 1 && style->true_acc == 0 && i == 0)
		style->width += 1;
	style->acc -= ft_size(i);
	if (style->acc < 0)
		style->acc = 0;
	if (i < 0)
		style->width = style->width - style->acc - ft_size(i) - 1
		- style->space;
	else
		style->width = style->width - style->acc - ft_size(i) - style->plus
		- style->space;
	if (i < 0 || style->plus == 1)
		style->space = 0;
	if (style->minus == 1)
		ft_number_left(style, i);
	else
		ft_number_right(style, i);
}

void		ft_number(char c, t_style *style, va_list vlist)
{
	if (c == 'D')
	{
		style->hh = 0;
		style->h = 0;
		style->l = 0;
		style->ll = 0;
		style->j = 0;
		ft_number2(style, va_arg(vlist, long long));
	}
	else if (style->l == 1)
		ft_number2(style, va_arg(vlist, long));
	else if (style->h == 1)
		ft_number2(style, va_arg(vlist, int));
	else if (style->ll == 1)
		ft_number2(style, va_arg(vlist, long long));
	else if (style->hh == 1)
		ft_number2(style, va_arg(vlist, int));
	else if (style->j == 1)
		ft_number2(style, va_arg(vlist, intmax_t));
	else if (style->z == 1)
		ft_number2(style, va_arg(vlist, size_t));
	else
		ft_number2(style, va_arg(vlist, int));
}
