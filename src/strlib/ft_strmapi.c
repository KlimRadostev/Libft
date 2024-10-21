/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 20:20:19 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 20:04:44 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "strlib.h"

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
