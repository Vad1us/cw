/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:12:01 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/30 16:12:02 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		k;
	char	*str;
	int		check;

	k = 0;
	check = -1;
	str = (char*)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			check = 1;
			k = i;
		}
		i++;
	}
	if (c == '\0')
		return (&str[i]);
	if (check == 1)
		return (&str[k]);
	return (NULL);
}
