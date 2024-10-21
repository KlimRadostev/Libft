/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 01:23:57 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:40:42 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

bool	stack_empty(t_stack *s)
{
	return (!s->top);
}

void	*stack_peek(t_stack *s)
{
	return (stack_empty(s) ? NULL : s->top->content);
}

t_stack	*stack_init(void)
{
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	tmp->top = 0;
	tmp->len = 0;
	return (tmp);
}

void	*pop(t_stack *stack)
{
	t_node	*tmp;
	void	*ret;

	if (stack_empty(stack))
		return (0);
	tmp = stack->top;
	ret = stack->top->content;
	stack->top = stack->top->next;
	free(tmp);
	stack->len--;
	return (ret);
}

void	push(t_stack *stack, void *content)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->content = content;
	tmp->next = stack->top;
	stack->top = tmp;
	stack->len++;
}
