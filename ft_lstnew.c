/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:55:28 by kradoste          #+#    #+#             */
/*   Updated: 2018/06/01 14:52:41 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	if (!(node = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		node->content = ft_memalloc(content_size);
		node->content = ft_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	return (node);
}
