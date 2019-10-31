/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extralib2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 22:29:10 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 22:59:18 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

#include "printf.h"

size_t		pf_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		*pf_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}

char		*pf_strcpy(char *dst, const char *src)
{
	int	i;

	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = src[i];
	return (dst);
}

char		*pf_strcat(char *s1, const char *s2)
{
	int	i;
	int	n;

	n = pf_strlen(s1);
	i = 0;
	while (s2[i])
	{
		s1[n + i] = s2[i];
		i++;
	}
	s1[n + i] = '\0';
	return (s1);
}

char		*pf_strdup(const char *s1)
{
	char	*key;
	size_t	i;

	i = pf_strlen(s1);
	if (!(key = (char *)malloc(sizeof(char) * i + 1)))
		return ((void*)0);
	pf_strcpy(key, s1);
	return (key);
}
