/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 16:25:57 by kradoste          #+#    #+#             */
/*   Updated: 2018/06/01 14:51:49 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	tens(int n, int *x)
{
	int	tenner;

	tenner = 1;
	while (n >= 9 || n <= -9)
	{
		tenner *= 10;
		n /= 10;
		(*x)++;
	}
	return (tenner);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		x;
	int		i;
	int		tenner;

	i = 0;
	x = 1;
	tenner = tens(n, &x);
	(n < 0) && (x++);
	if (!(str = (char *)malloc(sizeof(char) * (x + 1))))
		return (NULL);
	str[x] = '\0';
	if (n < 0)
	{
		i++;
		str[0] = '-';
	}
	while (i < x)
	{
		str[i++] = ft_abs((n / tenner) % 10) + 48;
		tenner /= 10;
	}
	return (str);
}
