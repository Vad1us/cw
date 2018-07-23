/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:49:23 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/06 16:49:25 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_r(char *n)
{
	int		fd;
	int		size;
	char	buf[10000];
	char	*ret;

	fd = open(n, O_RDONLY);
	if (fd <= 0)
		return ("File could not open.\n");
	else
	{
		size = read(fd, buf, 10000);
		buf[size] = '\0';
		close(fd);
		ret = buf;
		return (ret);
	}
}
