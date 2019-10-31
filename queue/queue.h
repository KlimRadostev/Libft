/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:16:53 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:21:40 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include <stdbool.h>

# include "../linklistlib/linklist.h"

typedef struct	s_queue
{
	int			len;
	t_node		*first;
	t_node		*last;
}				t_queue;

bool			queue_empty(t_queue *queue);
t_queue			*queue_init(void);
void			*dequeue(t_queue *queue);
void			enqueue(t_queue *queue, void *content);
void			*queue_peek(t_queue *queue);
int				queue_len(t_queue *queue);
void			fronqueue(t_queue *queue, void *content);
void			sort_queue(t_queue *queue);

#endif
