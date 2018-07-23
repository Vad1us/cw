/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:40:30 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/01 17:40:31 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../printf.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	s = (char*)malloc(sizeof(char) * size + 1);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (size)
	{
		s[i] = '\0';
		i++;
		size--;
	}
	s[i] = '\0';
	return (s);
}
