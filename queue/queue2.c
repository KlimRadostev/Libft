/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:09:48 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:43:10 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../functionality/functionality.h"
#include "queue.h"

int		queue_len(t_queue *queue)
{
	t_node	*head;
	int		len;

	if (!queue || queue_empty(queue))
		return (0);
	head = queue->first;
	len = 0;
	while (head)
	{
		head = head->next;
		len++;
	}
	return (len);
}

void	fronqueue(t_queue *queue, void *content)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->content = content;
	tmp->next = 0;
	tmp->next = queue->first;
	queue->first = tmp;
	if (queue_empty(queue))
		queue->last = tmp;
}

/*
**THIS IS FOR A QUEUE OF QUEUES ACCORDING TO HOW LONG THE QUEUES ARE
*/

void	sort_queue(t_queue *queue)
{
	t_node	*head;
	t_node	*ptr;
	t_node	*end_ptr;
	int		swap;

	head = queue->first;
	end_ptr = 0;
	swap = 1;
	while (swap)
	{
		swap = 0;
		ptr = head;
		while (ptr->next != end_ptr)
		{
			if (queue_len(ptr->content) > queue_len(ptr->next->content))
			{
				ft_swap(ptr, ptr->next, sizeof(ptr));
				swap = 1;
			}
			ptr = ptr->next;
		}
		end_ptr = ptr;
	}
}
