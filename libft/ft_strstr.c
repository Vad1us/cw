/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:42:31 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/30 15:42:32 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b;
	char	*l;
	int		i;
	int		k;

	i = 0;
	k = 0;
	b = (char*)big;
	l = (char*)little;
	if (l[k] == '\0')
		return (b);
	while (b[i])
	{
		k = 0;
		while (b[i] == l[k] && b[i] && l[k])
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
