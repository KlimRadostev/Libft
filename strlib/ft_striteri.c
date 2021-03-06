/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 18:07:44 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 19:53:51 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "strlib.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s == (void *)0 || f == (void *)0)
		return ;
	while (s != (void *)0 && *s)
		f(i++, s++);
}
