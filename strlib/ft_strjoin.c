/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 22:23:48 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 20:01:33 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return ((void *)0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
