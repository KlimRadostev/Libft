/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:24:38 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/30 15:18:16 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

#include "deck.h"

void		*peak_front(t_deck *deck)
{
	return (!deck_empty(deck) ? deck->first->content : NULL);
}

void		*peak_back(t_deck *deck)
{
	return (!deck_empty(deck) ? deck->last->content : NULL);
}

void		push_front(t_deck *deck, void *content)
{
	t_deck_node	*tmp;

	tmp = deck_node_memory(content);
	if (deck_empty(deck))
	{
		deck->first = tmp;
		deck->last = tmp;
		tmp->next = 0;
		tmp->prev = 0;
	}
	else
	{
		tmp->prev = deck->first;
		deck->first->next = tmp;
		tmp->next = 0;
		deck->first = tmp;
	}
	deck->len++;
}

void		push_back(t_deck *deck, void *content)
{
	t_deck_node	*tmp;

	tmp = deck_node_memory(content);
	if (deck_empty(deck))
	{
		deck->first = tmp;
		deck->last = tmp;
		tmp->next = 0;
		tmp->prev = 0;
	}
	else
	{
		tmp->next = deck->last;
		deck->last->prev = tmp;
		tmp->prev = 0;
		deck->last = tmp;
	}
	deck->len++;
}
