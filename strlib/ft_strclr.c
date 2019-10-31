/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 13:20:58 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 22:10:30 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "strlib.h"

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

void		ft_strclr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = ft_strlen(s);
	ft_bzero((void *)s, i);
}
