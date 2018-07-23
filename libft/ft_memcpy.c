/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:17:19 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/27 17:17:20 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*s2;
	int		i;

	i = (int)n - 1;
	s = (char*)dst;
	s2 = (char*)src;
	while (n > 0)
	{
		s[i] = s2[--n];
		i--;
	}
	return (s);
}
