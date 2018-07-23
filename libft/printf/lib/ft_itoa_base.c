/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 16:41:47 by vradchen          #+#    #+#             */
/*   Updated: 2018/03/24 16:41:49 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../printf.h"

static char		*ft_zero(void)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static int		ft_count(long long n, int b)
{
	long long i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while ((n / b) > 0)
	{
		n = n / b;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(long long n, int b)
{
	char			*str;
	int				size;
	char			*base;
	unsigned int	k;

	if (n == 0)
		return (ft_zero());
	base = "0123456789abcdef";
	size = ft_count(n, b);
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (n < 0)
		k = -n;
	else
		k = n;
	str[size + 1] = '\0';
	while (k > 0)
	{
		str[size] = base[k % b];
		k = k / b;
		size--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
