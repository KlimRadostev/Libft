/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlStrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:42:57 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:51:40 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "get_next_line.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char*p;

	p = (unsigned char *)b;
	while (len)
	{
		p[len - 1] = (unsigned char)c;
		len--;
	}
	return (b);
}

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

static void	*ft_memalloc(size_t size)
{
	void*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

char		*gnl_strnew(size_t size)
{
	return ((char *)ft_memalloc(size + 1));
}
