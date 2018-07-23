/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:47:48 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/30 17:47:48 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	if (size != 0)
	{
		s = (char*)malloc(sizeof(size_t) * size);
		if (s == NULL)
			return (NULL);
		while (s[i])
		{
			s[i] = 0;
			i++;
		}
		return (s);
	}
	return (NULL);
}
