/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:27:36 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:42:44 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

# include "../linklistlib/linklist.h"

typedef struct	s_stack
{
	int		len;
	t_node	*top;
}				t_stack;

bool			stack_empty(t_stack *s);
void			*stack_peek(t_stack *s);
t_stack			*stack_init(void);
void			*pop(t_stack *stack);
void			push(t_stack *stack, void *content);

#endif
