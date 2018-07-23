/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:45:59 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/01 13:46:00 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(const char *s, char c, int i)
{
	int len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char		**ft_split(const char *s, char c, char **s2)
{
	int		i2;
	int		index;
	int		len;
	int		i;

	i = 0;
	index = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			len = ft_size(s, c, i);
			s2[index] = (char*)malloc(sizeof(char) * len + 1);
			if (s2[index] == NULL)
				return (NULL);
			i2 = 0;
			while (len-- > 0)
				s2[index][i2++] = s[i++];
			s2[index++][i2] = '\0';
			i--;
		}
		i++;
	}
	s2[index] = (char*)'\0';
	return (s2);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		len;
	char	**s2;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while (s[i])
	{
		if ((s[0] != c && i == 0) || (s[i] != c && s[i - 1] == c))
			len++;
		i++;
	}
	s2 = (char**)malloc(sizeof(char*) * len + 1);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	s2 = ft_split(s, c, s2);
	return (s2);
}
