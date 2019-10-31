/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 14:36:14 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/30 16:50:18 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "linklist.h"

static void	lnls_memdel(void **ap)
{
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = (void *)0;
}

void		ft_lstdelone(t_node **alst, void (*del)(void *, size_t))
{
	del((*alst)->content, (*alst)->content_size);
	lnls_memdel((void **)alst);
}
