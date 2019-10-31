/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcountfix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 15:58:29 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 21:32:10 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionality.h"

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
