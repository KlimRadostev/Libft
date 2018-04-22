/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 22:30:51 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/17 17:36:24 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		while (needle[i] == haystack[i])
		{
			if (!needle[i + 1])
				return ((char *)haystack);
			if (x + i >= len)
				return ((void *)0);
			i++;
		}
		x++;
		haystack++;
		i = 0;
	}
	return ((void *)0);
}
