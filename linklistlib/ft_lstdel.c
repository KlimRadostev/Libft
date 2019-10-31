/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:48:33 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/30 16:53:59 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "linklist.h"

void	ft_lstdel(t_node **alst, void (*del)(void *, size_t))
{
	t_node	*tmp;

	if (*alst)
	{
		tmp = (*alst)->next;
		ft_lstdelone(alst, del);
		ft_lstdel(&(tmp), del);
	}
}
