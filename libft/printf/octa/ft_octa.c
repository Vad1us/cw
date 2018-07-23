/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_octa.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:50:04 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/26 19:50:06 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_octa2(char c, t_style *style, unsigned long long i)
{
	char *s;

	if (style->h == 1 && c == 'o')
		i = (unsigned short)i;
	if (style->hh == 1 && c == 'o')
		i = (unsigned char)i;
	s = ft_uitoa_base(i, 8);
	if (i == 0 && style->flag == 0)
		style->sharp = 0;
	if (style->acc != 0 || style->minus == 1)
		style->zero = 0;
	if (style->flag == 1 && style->true_acc == 0 && ft_strcmp(s, "0") == 0)
		style->width += 1;
	style->acc = style->acc - ft_strlen(s);
	if (style->acc < 0)
		style->acc = 0;
	style->width = style->width - style->acc - ft_strlen(s) -
		style->sharp;
	if (style->minus == 1)
		ft_octa_left(style, s);
	else
		ft_octa_right(style, s);
}

void		ft_octa(char c, t_style *style, va_list vlist)
{
	if (c == 'O')
		ft_octa2(c, style, va_arg(vlist, unsigned long long));
	else if (style->l == 1)
		ft_octa2(c, style, va_arg(vlist, unsigned long));
	else if (style->h == 1)
		ft_octa2(c, style, va_arg(vlist, unsigned int));
	else if (style->ll == 1)
		ft_octa2(c, style, va_arg(vlist, unsigned long long));
	else if (style->hh == 1)
		ft_octa2(c, style, va_arg(vlist, unsigned int));
	else if (style->j == 1)
		ft_octa2(c, style, va_arg(vlist, uintmax_t));
	else if (style->z == 1)
		ft_octa2(c, style, va_arg(vlist, size_t));
	else
		ft_octa2(c, style, va_arg(vlist, unsigned int));
}
