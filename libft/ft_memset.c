/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:42:38 by vradchen          #+#    #+#             */
/*   Updated: 2017/11/16 14:42:39 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*bb;
	unsigned char	cc;

	bb = (char*)b;
	cc = c;
	while (len > 0)
		bb[--len] = cc;
	return (bb);
}
