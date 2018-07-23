/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:22:44 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/10 17:22:46 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_part2(t_style *style)
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

void		ft_hex_left(char c, t_style *style, char *s)
{
	if (style->sharp == 1)
	{
		write(1, "0", 1);
		write(1, &c, 1);
		style->count += 2;
	}
	while (style->acc > 0)
	{
		write(1, "0", 1);
		style->count++;
		style->acc--;
	}
	if (!(style->flag == 1 && style->true_acc == 0 && ft_strcmp(s, "0") == 0))
	{
		ft_putstr(s);
		style->count += ft_strlen(s);
	}
	free(s);
	ft_part2(style);
}
