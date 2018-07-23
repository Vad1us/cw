/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:28:48 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/17 16:28:49 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

void		ft_initial_style(t_style *style)
{
	style->true_acc = 0;
	style->acc = 0;
	style->width = 0;
	style->minus = 0;
	style->plus = 0;
	style->space = 0;
	style->sharp = 0;
	style->zero = 0;
	style->l = 0;
	style->ll = 0;
	style->h = 0;
	style->hh = 0;
	style->j = 0;
	style->z = 0;
	style->flag = 0;
}
