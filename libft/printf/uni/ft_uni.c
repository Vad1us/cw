/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:05:24 by vradchen          #+#    #+#             */
/*   Updated: 2018/04/13 16:05:25 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static void	ft_part3(unsigned int i2)
{
	unsigned char	byte;

	byte = 240 | (i2 >> 18);
	write(1, &byte, 1);
	byte = 128 | ((i2 << 14) >> 26);
	write(1, &byte, 1);
	byte = 128 | ((i2 << 20) >> 26);
	write(1, &byte, 1);
	byte = 128 | ((i2 << 26) >> 26);
	write(1, &byte, 1);
}

static void	ft_part2(unsigned int i2)
{
	unsigned char	byte;

	byte = 224 | (i2 >> 12);
	write(1, &byte, 1);
	byte = 128 | ((i2 << 20) >> 26);
	write(1, &byte, 1);
	byte = 128 | ((i2 << 26) >> 26);
	write(1, &byte, 1);
}

void		ft_uni(int i)
{
	char			*str;
	unsigned int	i2;
	unsigned char	byte;

	i2 = i;
	str = ft_itoa_base(i, 2);
	if (ft_strlen(str) < 8)
		write(1, &i2, 1);
	else if (ft_strlen(str) < 12)
	{
		byte = 192 | (i2 >> 6);
		write(1, &byte, 1);
		byte = 128 | ((i2 << 26) >> 26);
		write(1, &byte, 1);
	}
	else if (ft_strlen(str) < 17)
		ft_part2(i2);
	else
		ft_part3(i2);
	free(str);
}
