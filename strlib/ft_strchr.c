/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 17:48:42 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 19:50:17 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlib.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return ((char *)s);
	return ((void *)0);
}