/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 18:37:33 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/01 18:37:34 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;
	t_list	*head;

	if (lst == NULL || f == NULL)
		return (NULL);
	l = f(lst);
	head = l;
	while (lst->next)
	{
		lst = lst->next;
		l->next = f(lst);
		l = l->next;
	}
	return (head);
}
