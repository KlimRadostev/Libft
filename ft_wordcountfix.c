/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcountfix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:58:29 by kradoste          #+#    #+#             */
/*   Updated: 2018/04/23 16:14:43 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcountfix(const char *str, char c)
{
	int	w;
	int	n;

	n = 0;
	w = 0;
	while (str[n])
	{
		if (str[n] != c)
			w++;
		while (str[n] != c && str[n + 1])
			n++;
		n++;
	}
	return (w);
}
