/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:15:24 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/12 14:15:25 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check(char *buffer)
{
	while (*buffer != '\0')
	{
		if (*buffer == '\n')
			return (0);
		buffer++;
	}
	return (1);
}

static char		*ft_trim(char *s)
{
	int			i;
	char		*s2;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static int		ft_ez(char *str)
{
	ft_strdel(&str);
	return (0);
}

static int		ft_w2(char **line, char **buffer)
{
	char		*buffer2;
	char		*str;

	buffer2 = ft_strdup(*buffer);
	ft_strdel(buffer);
	str = buffer2;
	if (*buffer2 == '\0')
		return (ft_ez(str));
	*line = ft_trim(buffer2);
	if (*line == NULL)
	{
		*line = ft_strdup(buffer2);
		while (*buffer2)
			buffer2++;
		*buffer = ft_strdup(buffer2);
		ft_strdel(&str);
		return (1);
	}
	while (*buffer2 != '\n')
		buffer2++;
	buffer2++;
	*buffer = ft_strdup(buffer2);
	ft_strdel(&str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	int			n;
	char		*tmp;
	char		*s;

	n = 1;
	if (fd < 0 || !line || fd > OPEN_MAX)
		return (-1);
	if (buffer[fd] == NULL)
		buffer[fd] = ft_strnew(0);
	while (n != 0 && ft_check(buffer[fd]) == 1)
	{
		tmp = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
		n = read(fd, tmp, BUFF_SIZE);
		if (n == -1)
			return (-1);
		tmp[n] = '\0';
		s = ft_strdup(buffer[fd]);
		ft_strdel(&buffer[fd]);
		buffer[fd] = ft_strjoin(s, tmp);
		ft_strdel(&tmp);
		ft_strdel(&s);
	}
	return (ft_w2(line, &buffer[fd]));
}
