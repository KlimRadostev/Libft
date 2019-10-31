/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjlist_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 15:56:06 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 00:28:29 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "adjlist.h"

void	free_graph(t_graph *graph)
{
	int		i;
	t_node	*tmp;
	t_node	*free_node;

	i = -1;
	if (!graph)
		return ;
	while (++i < graph->v)
	{
		if ((tmp = graph->array[i].head))
			while (tmp)
			{
				free_node = tmp;
				tmp = tmp->next;
				free(free_node);
			}
	}
	if (graph->v > 0)
		free(graph->array);
	if (graph)
		free(graph);
}
