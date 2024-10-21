/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 10:18:40 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 00:31:20 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "adjlist.h"

t_node		*new_adj_list_node(void *content)
{
	t_node *new_node;

	new_node = (t_node*)malloc(sizeof(t_node));
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

t_graph		*create_graph(int v)
{
	t_graph	*graph;
	int		i;

	graph = (t_graph *)malloc(sizeof(t_graph));
	graph->v = v;
	graph->array = (t_adj_list*)malloc(sizeof(t_adj_list) * v);
	i = -1;
	while (++i < v)
		graph->array[i].head = NULL;
	return (graph);
}

/*
** Add Edge doesn't store the node of the graph
** but rather it just stores the number of the node of the graph
** we might want to change that since it would be good to have info
** on the nodes, will have to restructure everything tho
*/
void		add_edge(t_graph *graph, int src, int dest)
{
	t_node *new_node;

	new_node = new_adj_list_node(&dest);
	new_node->next = graph->array[src].head;
	graph->array[src].head = new_node;
	new_node = new_adj_list_node(&src);
	new_node->next = graph->array[dest].head;
	graph->array[dest].head = new_node;
}

/*
** void		printGraph(t_graph *graph)
** {
**     for (int v = 0; v < graph->v; ++v)
**     {
**         t_adj_node *pCrawl = graph->array[v].head;
**         ft_printf("\n Adjacency list of vertex %d : ", v);
**         int first = 1;
**         while (pCrawl)
**         {
**             if (first) {
**                 ft_printf("%d", pCrawl->dest);
**                 first = 0;
**             }
**             else
**                 ft_printf(", %d", pCrawl->dest);
**             pCrawl = pCrawl->next;
**         }
**         ft_printf("\n");
**     }
** }
*/

t_graph		*graph_cpy(t_graph *graph)
{
	t_graph		*ret_graph;
	int			i;
	t_node		*tmp;
	int			*cpy;

	ret_graph = create_graph(graph->v);
	i = -1;
	while (++i < graph->v)
	{
		if ((tmp = graph->array[i].head))
			while (tmp)
			{
				cpy = tmp->content;
				add_edge(ret_graph, i, *cpy);
				tmp = tmp->next;
			}
	}
	return (ret_graph);
}


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
