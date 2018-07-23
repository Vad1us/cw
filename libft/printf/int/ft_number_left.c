/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 18:38:49 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/22 18:38:50 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_part2(char *str, t_style *style)
{
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

void		ft_number_left(t_style *style, long long i)
{
	char *str;

	if (style->h == 1)
		i = (short)i;
	if (style->hh == 1)
		i = (signed char)i;
	if (style->space == 1)
	{
		write(1, " ", 1);
		style->count++;
	}
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
	str = ft_itoa(i);
	ft_part2(str, style);
}
