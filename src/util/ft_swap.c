/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:18:20 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/30 13:19:46 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../memory/memory.h"
#include "functionality.h"

void	ft_swap(void *a, void *b, size_t len)
{
	char	*tmp;

	tmp = malloc(len);
	ft_memmove(tmp, a, len);
	ft_memmove(a, b, len);
	ft_memmove(b, tmp, len);
	free(tmp);
}
