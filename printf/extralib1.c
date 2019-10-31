/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extralib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:24:42 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 22:59:00 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

#include "printf.h"

static void	*ft_memset(void *b, int c, size_t len)
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

static void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

char		*pf_strchr(const char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return ((char *)s);
	return ((void *)0);
}

void		*pf_memalloc(size_t size)
{
	void	*mem;

	if (!(mem = malloc(size)))
		return (NULL);
	ft_bzero(mem, size);
	return (mem);
}

char		*pf_strnew(size_t size)
{
	return ((char *)pf_memalloc(size + 1));
}
