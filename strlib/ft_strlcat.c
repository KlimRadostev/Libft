/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:50:53 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 20:04:04 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "strlib.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	n;

	x = ft_strlen(src);
	i = ft_strlen(dst);
	n = 0;
	if (i >= size)
		return (x + size);
	while (src[n] && (n + i) < (size - 1))
	{
		dst[i + n] = src[n];
		n++;
	}
	dst[i + n] = '\0';
	return (x + i);
}
