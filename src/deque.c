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

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <libft/deque.h>

void		*peak_front(deque_t *dq)
{
	return (!deck_empty(deck) ? deck->first->content : NULL);
}

void		*peak_back(deque_t *deck)
{
	return (!deck_empty(deck) ? deck->last->content : NULL);
}

void		push_front(deque_t *deck, void *content)
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
