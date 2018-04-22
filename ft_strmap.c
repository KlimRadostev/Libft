/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:36:29 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/21 02:39:24 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	n;
	char	*str;

	n = -1;
	if (!s || !f || (!(str = ft_strnew(ft_strlen(s)))))
		return ((void *)0);
	while (s[++n])
		str[n] = f(s[n]);
	return (str);
}
