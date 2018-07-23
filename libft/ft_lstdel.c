/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:33:56 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/01 18:33:57 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l;

	l = *alst;
	if (alst != NULL && del != NULL)
	{
		while (l)
		{
			del(l->content, l->content_size);
			free(l);
			l = l->next;
		}
		*alst = NULL;
	}
}
