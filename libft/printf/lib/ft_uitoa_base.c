/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 16:43:15 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/27 16:43:16 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static char		*ft_zero(void)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char			*ft_uitoa_base(unsigned long long n, int b)
{
	char			str[60];
	char			*tmp;
	int				size;
	char			*base;
	int				i;

	if (n == 0)
		return (ft_zero());
	base = "0123456789abcdef";
	size = 0;
	i = 59;
	while (n != 0)
	{
		str[i--] = base[n % b];
		n = n / b;
		size++;
	}
	i++;
	tmp = (char*)malloc(sizeof(char) * (size + 1));
	size = 0;
	while (i <= 59)
		tmp[size++] = str[i++];
	tmp[size] = '\0';
	return (tmp);
}
