/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:23:06 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/28 16:23:07 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	char	*l;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	b = (char*)big;
	l = (char*)little;
	if (l[k] == '\0')
		return (b);
	while (b[i])
	{
		k = 0;
		while (b[i] == l[k] && b[i] && l[k] && i < len)
		{
			i++;
			k++;
		}
		i = i - k;
		if (l[k] == '\0')
			return (&b[i]);
		i++;
	}
	return (NULL);
}
