/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_n.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 12:48:39 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/27 12:48:41 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_left(t_style *style, char *s)
{
	while (style->acc > 0)
	{
		write(1, "0", 1);
		style->count++;
		style->acc--;
	}
	if (!(style->flag == 1 && ft_strcmp(s, "0") == 0))
	{
		ft_putstr(s);
		style->count += ft_strlen(s);
	}
	free(s);
	while (style->width > 0)
	{
		if (style->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		style->count++;
		style->width--;
	}
}

static void	ft_right(t_style *style, char *s)
{
	while (style->width > 0)
	{
		if (style->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		style->count++;
		style->width--;
	}
	while (style->acc > 0)
	{
		write(1, "0", 1);
		style->count++;
		style->acc--;
	}
	if (!(style->flag == 1 && ft_strcmp(s, "0") == 0))
	{
		ft_putstr(s);
		style->count += ft_strlen(s);
	}
	free(s);
}

static void	ft_n2(char c, t_style *style, unsigned long long i)
{
	char *s;

	if (style->h == 1 && c == 'u')
		i = (unsigned short)i;
	if (style->hh == 1 && c == 'u')
		i = (unsigned char)i;
	s = ft_uitoa_base(i, 10);
	if (style->acc != 0 || style->minus == 1)
		style->zero = 0;
	style->acc = style->acc - ft_strlen(s);
	if (style->acc < 0)
		style->acc = 0;
	style->width = style->width - style->acc - ft_strlen(s);
	if (style->minus == 1)
		ft_left(style, s);
	else
		ft_right(style, s);
}

void		ft_n(char c, t_style *style, va_list vlist)
{
	if (c == 'U')
		ft_n2(c, style, va_arg(vlist, unsigned long long));
	else if (style->l == 1)
		ft_n2(c, style, va_arg(vlist, unsigned long));
	else if (style->h == 1)
		ft_n2(c, style, va_arg(vlist, unsigned int));
	else if (style->ll == 1)
		ft_n2(c, style, va_arg(vlist, unsigned long long));
	else if (style->hh == 1)
		ft_n2(c, style, va_arg(vlist, unsigned int));
	else if (style->j == 1)
		ft_n2(c, style, va_arg(vlist, uintmax_t));
	else if (style->z == 1)
		ft_n2(c, style, va_arg(vlist, size_t));
	else
		ft_n2(c, style, va_arg(vlist, unsigned int));
}
