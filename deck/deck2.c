/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:09:36 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/30 15:16:54 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "deck.h"

t_deck_node	*deck_node_memory(void *content)
{
	t_deck_node	*ret;

	ret = (t_deck_node *)malloc(sizeof(t_deck_node));
	ret->prev = NULL;
	ret->next = NULL;
	ret->content = content;
	return (ret);
}

bool		deck_empty(t_deck *deck)
{
	return (!deck->first && !deck->last);
}

t_deck		*deck_init(void)
{
	t_deck	*tmp;

	tmp = (t_deck *)malloc(sizeof(t_deck));
	tmp->first = NULL;
	tmp->last = NULL;
	tmp->len = 0;
	return (tmp);
}

void		*pop_front(t_deck *deck)
{
	t_deck_node	*tmp;
	void		*ret;

	if (deck_empty(deck))
		return (NULL);
	tmp = deck->first;
	ret = deck->first->content;
	deck->first = deck->first->prev;
	if (!deck->first)
	{
		deck->first = NULL;
		deck->last = NULL;
	}
	else
		deck->first->next = NULL;
	tmp->prev = NULL;
	free(tmp);
	deck->len--;
	return (ret);
}

void		*pop_back(t_deck *deck)
{
	t_deck_node	*tmp;
	void		*ret;

	if (deck_empty(deck))
		return (NULL);
	tmp = deck->last;
	ret = deck->last->content;
	deck->last = deck->last->next;
	if (!deck->last)
	{
		deck->last = NULL;
		deck->first = NULL;
	}
	else
		deck->last->prev = NULL;
	tmp->next = NULL;
	free(tmp);
	deck->len--;
	return (ret);
}
