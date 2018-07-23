/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crossroad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:19:43 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/20 19:19:44 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

int		ft_crossroad(char c, t_style *style, va_list vlist)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' ||
		c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
		|| c == 'X' || c == 'c' || c == 'C' || c == '%')
	{
		if (c == '%')
			ft_bublik(style);
		if (c == 'i' || c == 'd' || c == 'D')
			ft_number(c, style, vlist);
		else if (c == 'S' || c == 's')
			ft_string(c, style, vlist);
		else if (c == 'p')
			ft_ointer(style, vlist);
		else if (c == 'o' || c == 'O')
			ft_octa(c, style, vlist);
		else if (c == 'u' || c == 'U')
			ft_n(c, style, vlist);
		else if (c == 'x' || c == 'X')
			ft_hex(c, style, vlist);
		else if (c == 'c' || c == 'C')
			ft_char(c, style, vlist);
		return (1);
	}
	return (0);
}
