/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 19:38:29 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/25 19:38:30 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_print_space(t_style *style)
{
	while (style->width > 0)
	{
		write(1, " ", 1);
		style->count++;
		style->width--;
	}
	ft_putstr("0x");
	style->count += 2;
	while (style->acc > 0)
	{
		write(1, "0", 1);
		style->count++;
		style->acc--;
	}
}

static void	ft_pointer_left(t_style *style, char *s)
{
	ft_putstr("0x");
	style->count += 2;
	while (style->acc > 0)
	{
		ft_putchar('0');
		style->count++;
		style->acc--;
	}
	if (!(style->flag == 1 && ft_strcmp(s, "0") == 0 && style->true_acc == 0))
	{
		ft_putstr(s);
		style->count += ft_strlen(s);
	}
	while (style->width > 0)
	{
		ft_putchar(' ');
		style->count++;
		style->width--;
	}
	free(s);
}

static void	ft_pointer_right(t_style *style, char *s)
{
	if (style->zero == 1)
	{
		ft_putstr("0x");
		style->count += 2;
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
	}
	else
		ft_print_space(style);
	if (!(style->flag == 1 && ft_strcmp(s, "0") == 0 && style->true_acc == 0))
	{
		ft_putstr(s);
		style->count += ft_strlen(s);
	}
	free(s);
}

void		ft_ointer(t_style *style, va_list vlist)
{
	char				*s;
	unsigned long long	p;

	p = va_arg(vlist, unsigned long long);
	if (style->minus == 1 || style->flag == 1)
		style->zero = 0;
	s = ft_uitoa_base(p, 16);
	style->acc = style->acc - ft_strlen(s);
	if (style->acc < 0)
		style->acc = 0;
	style->width = style->width - style->acc - ft_strlen(s) - 2;
	if (style->minus == 1)
		ft_pointer_left(style, s);
	else
		ft_pointer_right(style, s);
}
