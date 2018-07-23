/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:57:38 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/30 18:57:39 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

static char		*ft_zero(void)
{
	char				*str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char		*ft_part2(int i, int size, char *str)
{
	char *res;

	res = (char*)malloc(sizeof(char) * (size + 1));
	size = 0;
	while (i <= 59)
		res[size++] = str[i++];
	res[size] = '\0';
	return (res);
}

char			*ft_itoa(long long n)
{
	unsigned long long	k;
	char				str[60];
	int					size;
	int					i;

	if (n == 0)
		return (ft_zero());
	size = 0;
	i = 59;
	if (n < 0)
	{
		k = -n;
		size++;
	}
	else
		k = n;
	while (k != 0)
	{
		str[i--] = k % 10 + '0';
		k = k / 10;
		size++;
	}
	i++;
	return (ft_part2(i, size, str));
}
