/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:23:14 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/28 12:23:15 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	i = 0;
	if (dstsize < ft_strlen(dst))
	{
		return (ft_strlen(src) + dstsize);
	}
	else
	{
		while (dst[i])
			i++;
		while (*src && (i < dstsize - 1))
		{
			dst[i] = *src;
			src++;
			i++;
		}
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
