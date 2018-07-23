/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:44:52 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/01 12:44:53 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_return(char const *s, int len)
{
	int		i;
	char	*s2;
	int		k;

	k = 0;
	i = 0;
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (k < len)
	{
		s2[k] = s[i];
		k++;
		i++;
	}
	s2[k] = '\0';
	return (s2);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;

	if (s == NULL)
		return (NULL);
	len = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (s[i])
	{
		len++;
		i++;
	}
	i--;
	if (len > 0)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			len--;
			i--;
		}
	}
	return (ft_return(s, len));
}
