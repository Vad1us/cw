/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 18:26:20 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/27 18:26:21 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*s2;

	s = (unsigned char*)src;
	s2 = (unsigned char*)dst;
	i = 0;
	while (n > i)
	{
		s2[i] = s[i];
		if (s[i] == (unsigned char)c)
			return (&s2[i + 1]);
		i++;
	}
	return (NULL);
}
