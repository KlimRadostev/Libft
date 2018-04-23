/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:07:22 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/23 16:09:18 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcount(const char *str)
{
	int	x;
	int	n;

	x = 0;
	n = 0;
	while (str[n])
	{
		if (!ft_isspace(str[n]))
			x++;
		while (!ft_isspace(str[n]) && str[n + 1])
			n++;
		n++;
	}
	return (x);
}
