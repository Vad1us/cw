/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:49:29 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/28 15:49:30 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		check;

	check = -1;
	str = (char*)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
		{
			check = 1;
			break ;
		}
		i++;
	}
	if (c == '\0' || check == 1)
		return (&str[i]);
	return (NULL);
}
