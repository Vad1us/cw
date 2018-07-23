/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:18:44 by vradchen          #+#    #+#             */
/*   Updated: 2017/12/06 17:18:50 by vradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_recursive_factorial(size_t nb)
{
	if (nb == 0 || nb > 12)
		return (0);
	if (nb > 1)
		nb = nb * ft_recursive_factorial(nb - 1);
	else
		return (1);
	return (nb);
}
