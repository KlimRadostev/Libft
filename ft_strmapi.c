/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:20:19 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/21 02:38:51 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	n;
	char	*str;

	n = -1;
	if (!s || !f || (!(str = ft_strnew(ft_strlen(s)))))
		return ((void *)0);
	while (s[++n])
		str[n] = f(n, s[n]);
	return (str);
}
