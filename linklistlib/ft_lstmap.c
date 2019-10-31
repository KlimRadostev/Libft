/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 16:30:03 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/30 16:49:35 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "linklist.h"

t_node	*ft_lstmap(t_node *lst, t_node *(*f)(t_node *elem))
{
	t_node	*list;

	if (lst != NULL && f != NULL)
	{
		list = f(lst);
		if (list != NULL || lst->next != NULL)
			list->next = ft_lstmap(lst->next, f);
		return (list);
	}
	return (NULL);
}
