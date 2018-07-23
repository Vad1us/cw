/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:50:03 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/01 17:50:04 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l;

	l = (t_list*)malloc(sizeof(t_list));
	if (l == NULL)
		return (NULL);
	if (content == NULL)
	{
		l->content = NULL;
		l->content_size = 0;
	}
	else
	{
		l->content = malloc(content_size);
		if (l->content == NULL)
			return (NULL);
		l->content_size = content_size;
		ft_memcpy(l->content, content, content_size);
	}
	l->next = NULL;
	return (l);
}
