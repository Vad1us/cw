/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_hex.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:31:51 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/27 16:31:52 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char		*ft_down(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	return (s);
}

static void	ft_hex2(char c, t_style *style, unsigned long long i)
{
	char	*s;

	if (style->h == 1)
		i = (unsigned short)i;
	if (style->hh == 1)
		i = (unsigned char)i;
	s = ft_uitoa_base(i, 16);
	if (c == 'X')
		s = ft_down(s);
	if (i == 0)
		style->sharp = 0;
	if (style->acc != 0 || style->minus == 1)
		style->zero = 0;
	if (style->flag == 1 && style->true_acc == 0 && ft_strcmp(s, "0") == 0)
		style->width += 1;
	style->acc -= ft_strlen(s);
	if (style->acc < 0)
		style->acc = 0;
	style->width = style->width - style->acc - ft_strlen(s) -
		(2 * style->sharp);
	if (style->minus == 1)
		ft_hex_left(c, style, s);
	else
		ft_hex_right(c, style, s);
}

void		ft_hex(char c, t_style *style, va_list vlist)
{
	if (style->l == 1)
		ft_hex2(c, style, va_arg(vlist, unsigned long));
	else if (style->h == 1)
		ft_hex2(c, style, va_arg(vlist, unsigned int));
	else if (style->ll == 1)
		ft_hex2(c, style, va_arg(vlist, unsigned long long));
	else if (style->hh == 1)
		ft_hex2(c, style, va_arg(vlist, unsigned int));
	else if (style->j == 1)
		ft_hex2(c, style, va_arg(vlist, uintmax_t));
	else if (style->z == 1)
		ft_hex2(c, style, va_arg(vlist, size_t));
	else
		ft_hex2(c, style, va_arg(vlist, unsigned int));
}
