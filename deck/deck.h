/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deck.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 21:17:17 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/30 15:16:03 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DECK_H
# define DECK_H

# include <stdbool.h>

typedef struct	s_deck_node
{
	void				*content;
	struct s_deck_node	*next;
	struct s_deck_node	*prev;
}				t_deck_node;

typedef struct	s_deck
{
	int			len;
	t_deck_node	*first;
	t_deck_node	*last;
}				t_deck;

t_deck			*deck_init(void);
t_deck_node		*deck_node_memory(void *content);
bool			deck_empty(t_deck *deck);
void			*peak_front(t_deck *deck);
void			*peak_back(t_deck *deck);
void			push_front(t_deck *deck, void *content);
void			push_back(t_deck *deck, void *content);
void			*pop_front(t_deck *deck);
void			*pop_back(t_deck *deck);

#endif
