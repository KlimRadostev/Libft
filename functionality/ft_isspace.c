/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:39:43 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 21:30:29 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functionality.h"

int		ft_isspace(char c)
{
	if (c == '\n' || c == ' ' || c == '\t')
		return (1);
	else if (c == '\v' || c == '\r' || c == '\f')
		return (1);
	return (0);
}