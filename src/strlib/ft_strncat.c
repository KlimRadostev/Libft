/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:31:03 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 20:05:03 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "strlib.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	x;
	int	i;

	x = ft_strlen(s1);
	i = 0;
	while (s2[i] && n > 0)
	{
		s1[x + i] = s2[i];
		i++;
		n--;
	}
	s1[x + i] = '\0';
	return (s1);
}
