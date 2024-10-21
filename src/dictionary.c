/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:13:15 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/30 14:30:19 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "../strlib/strlib.h"
#include "dictionary.h"

unsigned	hash(char *input)
{
	unsigned	hash;
	unsigned	i;

	hash = 0x1337;
	i = 0;
	while (input[i] != '\0')
	{
		hash += (hash << 5) - input[i];
		hash -= (hash >> 2) + input[i];
		i++;
	}
	return (hash);
}

t_dict		*dict_init(int capacity)
{
	t_dict	*ret;
	int		i;

	ret = (t_dict *)malloc(sizeof(t_dict));
	ret->capacity = capacity;
	ret->items = (t_dict_item **)malloc(sizeof(t_dict_item *) * capacity);
	i = -1;
	while (++i < capacity)
		ret->items[i] = NULL;
	return (ret);
}

int			dict_insert(t_dict *dict, char *key, t_dict_node *value)
{
	unsigned	h;
	t_dict_item	*item;

	h = hash(key) % (dict->capacity);
	if ((item = dict->items[h]) != NULL)
	{
		while (item->next)
			item = item->next;
		item->next = (t_dict_item *)malloc(sizeof(t_dict_item));
		item = item->next;
	}
	else
	{
		dict->items[h] = (t_dict_item *)malloc(sizeof(t_dict_item));
		item = dict->items[h];
	}
	item->value = value;
	item->key = ft_strdup(key);
	item->next = NULL;
	return (1);
}

t_dict_node	*dict_search(t_dict *dict, char *key)
{
	unsigned	index;
	t_dict_item	*cursor;

	index = hash(key) % dict->capacity;
	if (!(cursor = dict->items[index]))
		return (NULL);
	while (cursor)
	{
		if (!ft_strcmp(cursor->key, key))
			return (cursor->value);
		cursor = cursor->next;
	}
	return (NULL);
}

void		free_dict(t_dict *dict)
{
	int			i;
	t_dict_item	*item;
	t_dict_item	*tmp;

	i = -1;
	while (++i < dict->capacity)
	{
		item = dict->items[i];
		while (item)
		{
			tmp = item;
			item = item->next;
			free(tmp->key);
			free(tmp->value->name);
			free(tmp->value);
			free(tmp);
		}
		free(item);
	}
	free(dict->items);
	free(dict);
}
