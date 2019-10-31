/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 11:59:28 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 21:29:53 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionality.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}