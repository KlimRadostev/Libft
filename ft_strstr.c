/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 21:27:07 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/16 22:59:58 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack)
	{
		while (needle[i] == haystack[i])
		{
			if (!needle[i + 1])
				return ((char *)haystack);
			i++;
		}
		haystack++;
		i = 0;
	}
	return ((void *)0);
}
