/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 18:38:48 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 21:31:11 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionality.h"

int	ft_power(int x, int base)
{
	if (base > 40)
		return (0);
	if (!x || base < 0)
		return (0);
	if (!base)
		return (1);
	return (x * ft_power(x, base - 1));
}
