/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 23:02:02 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/21 21:48:06 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	n;
	size_t	i;
	size_t	x;

	if (!s)
		return (ft_strdup(""));
	x = ft_strlen((char *)s) - 1;
	i = 0;
	if (!s[i])
		return (ft_strdup(""));
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (i > x)
		return (ft_strdup(""));
	while ((s[x] == ' ' || s[x] == '\n' || s[x] == '\t') && x != 0)
		x--;
	if (!(str = ft_strnew(x - i + 1)))
		return ((void *)0);
	n = 0;
	while (i < x + 1)
		str[n++] = s[i++];
	if (x == 0)
		return (ft_strdup(""));
	return (str);
}
