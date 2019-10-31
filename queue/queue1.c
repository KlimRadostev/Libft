/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:58:33 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:16:54 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "queue.h"

bool	queue_empty(t_queue *queue)
{
	return (!queue->first);
}

void	*queue_peek(t_queue *queue)
{
	return (queue_empty(queue) ? queue->first->content : NULL);
}

t_queue	*queue_init(void)
{
	t_queue *tmp;

	tmp = (t_queue *)malloc(sizeof(t_queue));
	tmp->first = NULL;
	tmp->last = NULL;
	tmp->len = 0;
	return (tmp);
}

void	*dequeue(t_queue *queue)
{
	t_node	*tmp;
	void	*ret;

	if (queue_empty(queue))
		return (NULL);
	tmp = queue->first;
	ret = queue->first->content;
	queue->first = queue->first->next;
	if (queue_empty(queue))
	{
		queue->first = NULL;
		queue->last = NULL;
	}
	free(tmp);
	queue->len--;
	return (ret);
}

void	enqueue(t_queue *queue, void *content)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->content = content;
	tmp->next = NULL;
	if (queue_empty(queue))
		queue->first = tmp;
	else
		queue->last->next = tmp;
	queue->last = tmp;
	queue->len++;
}
