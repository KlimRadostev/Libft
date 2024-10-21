/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 20:55:28 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:44:40 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "linklist.h"

static void	*lnls_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (len)
	{
		p[len - 1] = (unsigned char)c;
		len--;
	}
	return (b);
}

static void	*lnls_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	lnls_memset(mem, 0, size);
	return (mem);
}

static void	*lnls_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

t_node		*ft_lstnew(void const *content, size_t content_size)
{
	t_node	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	if (!content || !content_size)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		node->content = lnls_memalloc(content_size);
		node->content = lnls_memcpy(node->content, content, content_size);
		node->content_size = content_size;
	}
	return (node);
}
