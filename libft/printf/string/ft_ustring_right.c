/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustring_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:07:13 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/11 17:07:14 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static int	ft_ulen_char(wchar_t *str, t_style *style)
{
	int i;
	int len;

	len = 0;
	i = 0;
	while (style->acc >= len)
	{
		if (len + ft_usize(str[i]) > style->acc)
			break ;
		len += ft_usize(str[i]);
		i++;
	}
	return (len);
}

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

static void	ft_string_part1(t_style *style, wchar_t *str)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (str[i])
		len += ft_usize(str[i++]);
	if (style->minus == 1)
		style->zero = 0;
	if (str != NULL)
	{
		if (style->acc > len)
			style->acc = len;
		if (style->flag == 1)
			style->width -= ft_ulen_char(str, style);
		else
			style->width -= len;
	}
	else
	{
		if (style->acc > 6)
			style->acc = 6;
		style->width -= style->acc;
	}
	ft_width(style);
}

void		ft_ustring_right(t_style *style, wchar_t *str)
{
	if (str == NULL)
		str = L"(null)";
	ft_string_part1(style, str);
	if (style->flag == 1)
	{
		while (style->acc > 0 && *str && ft_usize(*str) <= style->acc)
		{
			ft_uni(*str);
			style->count += ft_usize(*str);
			style->acc -= ft_usize(*str);
			str++;
		}
	}
	else
	{
		while (*str)
		{
			ft_uni(*str);
			style->count += ft_usize(*str);
			str++;
		}
	}
}
