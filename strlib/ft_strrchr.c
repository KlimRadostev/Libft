/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 18:04:36 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 20:29:33 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlib.h"

char	*ft_strrchr(const char *s, int c)
{
	int	x;

	x = ft_strlen(s);
	while (s[x] != c && x > 0)
		x--;
	if (s[x] == c)
		return ((char *)&(s[x]));
	return ((void *)0);
}