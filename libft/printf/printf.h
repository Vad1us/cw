/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:56:36 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/19 14:56:38 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../libft.h"

typedef struct	s_style
{
	int		true_acc;
	int		acc;
	int		width;
	int		minus;
	int		plus;
	int		space;
	int		sharp;
	int		zero;
	int		l;
	int		ll;
	int		h;
	int		hh;
	int		j;
	int		z;
	int		count;
	int		flag;
}				t_style;

void			ft_invalid(char *f, t_style *style);
void			ft_initial_style(t_style *style);
int				ft_valid(char c);
int				ft_usize(int i);
void			ft_uni(int i);
void			ft_bublik(t_style *style);
int				ft_double_c(char *s, char c);
char			*ft_uitoa_base(unsigned long long n, int b);
char			*ft_itoa_base(long long n, int b);
int				ft_printf(char *format, ...);
int				ft_crossroad(char c, t_style *style, va_list vlist);
void			ft_hex(char c, t_style *style, va_list vlist);
void			ft_hex_right(char c, t_style *style, char *s);
void			ft_hex_left(char c, t_style *style, char *s);
void			ft_n(char c, t_style *style, va_list vlist);
void			ft_octa(char c, t_style *style, va_list vlist);
void			ft_octa_right(t_style *style, char *s);
void			ft_octa_left(t_style *style, char *s);
void			ft_ointer(t_style *style, va_list vlist);
void			ft_char(char c, t_style *style, va_list vlist);
void			ft_uchar(t_style *style, int i);
void			ft_string(char c, t_style *style, va_list vlist);
void			ft_ustring_left(t_style *style, wchar_t *str);
void			ft_ustring_right(t_style *style, wchar_t *str);
void			ft_number(char c, t_style *style, va_list vlist);
void			ft_number_left(t_style *style, long long i);
void			ft_number_right(t_style *style, long long i);

#endif
