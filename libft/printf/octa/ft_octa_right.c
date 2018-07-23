/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ocat_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:48:42 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/10 17:48:43 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_part2(t_style *style)
{
	while (style->width > 0)
	{
		write(1, " ", 1);
		style->count++;
		style->width--;
	}
	write(1, "0", 1);
	style->count += 1;
	style->acc--;
	while (style->acc > 0)
	{
		write(1, "0", 1);
		style->count++;
		style->acc--;
	}
}

static void	ft_print_zero(t_style *style)
{
	write(1, "0", 1);
	style->count += 1;
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

static void	ft_else(t_style *style)
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
}

void		ft_octa_right(t_style *style, char *s)
{
	if (style->sharp == 1)
	{
		if (style->zero == 1)
			ft_print_zero(style);
		else
			ft_part2(style);
	}
	else
		ft_else(style);
	if (!(style->flag == 1 && style->true_acc == 0 && ft_strcmp(s, "0") == 0))
	{
		ft_putstr(s);
		style->count += ft_strlen(s);
	}
	free(s);
}
