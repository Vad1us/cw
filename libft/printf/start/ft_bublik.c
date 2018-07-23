/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bublik.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 16:35:46 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/26 16:35:47 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_step1(t_style *style)
{
	while (style->width > 1)
	{
		if (style->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		style->count++;
		style->width--;
	}
	ft_putchar('%');
	style->count++;
}

void		ft_bublik(t_style *style)
{
	if (style->minus == 1)
	{
		ft_putchar('%');
		style->count++;
		while (style->width > 1)
		{
			if (style->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			style->count++;
			style->width--;
		}
	}
	else
		ft_step1(style);
}
