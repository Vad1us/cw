/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:24:55 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/01 18:24:56 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;

	l = *alst;
	if (alst != NULL && del != NULL)
	{
		if (l != NULL)
		{
			del(l->content, l->content_size);
			free(l);
			*alst = NULL;
		}
	}
}
