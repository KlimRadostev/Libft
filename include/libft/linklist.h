/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linklist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:25:43 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:46:48 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKLIST_H
# define LINKLIST_H

# include <string.h>

typedef struct	s_node
{
	void			*content;
	size_t			content_size;
	struct s_node	*next;
}				t_node;

void			ft_lstdelone(t_node **alst, void (*del)(void *, size_t));
t_node			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdel(t_node **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_node **alst, t_node *new);
void			ft_lstiter(t_node *lst, void (*f)(t_node *elem));
t_node			*ft_lstmap(t_node *lst, t_node *(*f)(t_node *elem));

#endif
