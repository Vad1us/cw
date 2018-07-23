/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:23:37 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/01 17:23:38 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	int		i2;
	char	*s3;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	s3 = (char*)malloc(sizeof(char) * len + 1);
	if (s3 == NULL)
		return (NULL);
	i = 0;
	i2 = 0;
	while (s1[i2])
		s3[i++] = s1[i2++];
	i2 = 0;
	while (s2[i2])
		s3[i++] = s2[i2++];
	s3[i] = '\0';
	return (s3);
}
