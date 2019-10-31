/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   joinDupGnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 21:49:17 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:51:50 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char		*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = src[i];
	return (dst);
}

static char		*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int	n;

	n = ft_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[n + i] = s2[i];
		i++;
	}
	s1[n + i] = '\0';
	return (s1);
}

char			*gnl_strdup(const char *s1)
{
	char	*key;
	size_t	i;

	i = ft_strlen(s1);
	if (!(key = (char *)malloc(sizeof(char) * i + 1)))
		return ((void*)0);
	ft_strcpy(key, s1);
	return (key);
}

char			*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(str = gnl_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return ((void *)0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
