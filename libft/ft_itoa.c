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

#include "libft.h"

static int		ft_size(int n)
{
	int				size;

	size = 0;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n / 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	char			*s;
	int				len;
	unsigned int	k;

	len = ft_size(n);
	s = (char*)malloc(sizeof(char) * len + 2);
	if (s == NULL)
		return (NULL);
	s[len + 1] = '\0';
	if (n < 0)
		k = -n;
	else
		k = n;
	while (len >= 0)
	{
		s[len] = k % 10 + '0';
		k = k / 10;
		len--;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
