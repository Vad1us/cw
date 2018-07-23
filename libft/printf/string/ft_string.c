/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:14:28 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:14:30 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_width(t_style *style)
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
}

static void	ft_string_left(t_style *style, char *str)
{
	if (str == NULL)
		str = "(null)";
	if (style->flag == 1)
	{
		while (style->acc > 0)
		{
			write(1, str, 1);
			style->count++;
			str++;
			style->acc--;
		}
	}
	else
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
			style->count++;
		}
	}
	ft_width(style);
}

static void	ft_string_right(t_style *style, char *str)
{
	ft_width(style);
	if (str == NULL)
		str = "(null)";
	if (style->flag == 1)
	{
		while (style->acc > 0 && *str)
		{
			write(1, str, 1);
			str++;
			style->count++;
			style->acc--;
		}
	}
	else
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
			style->count++;
		}
	}
}

static void	ft_string2(t_style *style, char *str)
{
	if (style->minus == 1)
		style->zero = 0;
	if (str != NULL)
	{
		if (style->acc > (int)ft_strlen(str))
			style->acc = ft_strlen(str);
		if (style->flag == 1)
			style->width -= style->acc;
		else
			style->width -= ft_strlen(str);
	}
	else
	{
		if (style->acc > 6)
			style->acc = 6;
		style->width -= style->acc;
	}
}

void		ft_string(char c, t_style *style, va_list vlist)
{
	char	*str;
	wchar_t	*ustr;

	str = NULL;
	str = va_arg(vlist, char*);
	if (c == 'S' || style->l == 1)
	{
		ustr = (wchar_t *)str;
		if (style->minus == 1)
			ft_ustring_left(style, (wchar_t *)str);
		else
			ft_ustring_right(style, (wchar_t *)str);
	}
	else if (style->minus == 1)
	{
		ft_string2(style, str);
		ft_string_left(style, str);
	}
	else
	{
		ft_string2(style, str);
		ft_string_right(style, str);
	}
}
