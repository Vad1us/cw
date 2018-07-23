/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/17 16:33:40 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/17 16:39:25 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <limits.h>

static char	*ft_step3(char *f, t_style *style, va_list vlist)
{
	if (ft_isdigit(*f))
	{
		if (*f == '0')
			style->zero = 1;
		style->width = ft_atoi(f);
		while (ft_isdigit(*f))
			f++;
		f--;
	}
	else if (*f == '.')
	{
		f++;
		if (*f == '*')
			style->acc = va_arg(vlist, int);
		else if (ft_isdigit(*f))
			style->acc = ft_atoi(f);
		while (ft_isdigit(*f))
			f++;
		f--;
		style->flag = 1;
		style->true_acc = style->acc;
	}
	f++;
	return (f);
}

static char	*ft_step2(char *f, t_style *style, va_list vlist)
{
	if (*f == 'h')
	{
		if (ft_double_c(f, 'h'))
			style->hh = 1;
		else if (style->hh != 1)
			style->h = 1;
	}
	else if (*f == 'l')
	{
		if (ft_double_c(f, 'l'))
			style->ll = 1;
		else if (style->ll != 1)
			style->l = 1;
	}
	else if (*f == 'j')
		style->j = 1;
	else if (*f == 'z')
		style->z = 1;
	return (ft_step3(f, style, vlist));
}

static char	*ft_step1(char *f, t_style *style, va_list vlist)
{
	while (*f != 's' && *f != 'S' && *f != 'p' && *f != 'd' && *f != 'D' &&
		*f != 'i' && *f != 'o' && *f != 'O' && *f != 'u' && *f != 'U' && *f !=
		'x' && *f != 'X' && *f != 'c' && *f != 'C' && *f != '\0' && *f != '%')
	{
		if (ft_valid(*f) == 0)
			break ;
		if (*f == '+')
			style->plus = 1;
		else if (*f == '#')
			style->sharp = 1;
		else if (*f == '-')
			style->minus = 1;
		else if (*f == ' ')
			style->space = 1;
		else if (*f == '*')
			style->width = va_arg(vlist, int);
		else if (*f == '0')
			style->zero = 1;
		f = ft_step2(f, style, vlist);
	}
	return (f);
}

int			ft_printf(char *format, ...)
{
	t_style	style;
	va_list	(vlist);

	va_start(vlist, format);
	style.count = 0;
	while (*format)
	{
		while (*format == '%')
		{
			ft_initial_style(&style);
			format = ft_step1(format + 1, &style, vlist);
			if (*format == '\0')
				break ;
			if (ft_crossroad(*format, &style, vlist) == 0 && *format)
				ft_invalid(format, &style);
			format++;
		}
		if (*format == '\0')
			break ;
		ft_putchar(*format);
		style.count++;
		format++;
	}
	va_end(vlist);
	return (style.count);
}
