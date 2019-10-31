/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictionary.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 16:13:17 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/23 14:34:39 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICTIONARY_H
# define DICTIONARY_H

typedef struct	s_dict_node {
	char		*name;
	int			id;
}				t_dict_node;

typedef struct	s_dict_item {
	char				*key;
	t_dict_node			*value;
	struct s_dict_item	*next;
}				t_dict_item;

typedef struct	s_dict {
	t_dict_item	**items;
	int			capacity;
}				t_dict;

unsigned		hash(char *input);
t_dict			*dict_init(int capacity);
int				dict_insert(t_dict *dict, char *key, t_dict_node *value);
t_dict_node		*dict_search(t_dict *dict, char *key);
void			free_dict(t_dict *dict);

#endif
