/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 19:55:26 by kradoste          #+#    #+#             */
/*   Updated: 2018/11/06 12:09:31 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	parse_width(char *str, t_printf *p, int max)
{
	int	i;

	i = 0;
	while (str[i] && i < max && p->width == 0)
	{
		if (ft_strchr("123456789", str[i]) && str[i - 1] != '.')
			p->width = ft_atoi(&str[i]);
		i++;
	}
}

void	parse_all(char *str, t_printf *p, int max)
{
	int	i;

	i = 0;
	while (str[i] && i < max)
	{
		(str[i] == '-') && (p->width *= -1);
		(str[i] == '#') && (p->hash = 1);
		(str[i] == '+') && (p->plus = 1);
		(str[i] == '.') && (p->dot = 1);
		(str[i] == ' ') && (p->space = 1);
		(!ft_strchr("123456789.", str[i - 1]) && str[i] == '0')
			&& (p->zero = 1);
		(str[i] == '.' && ft_strchr("0123456789", str[i + 1]))
			&& (p->pre = ft_atoi(&str[i + 1]));
		(str[i] == '.' && !ft_strchr("0123456789", str[i + 1]) && p->pre == -1)
			&& (p->pre = 0);
		i++;
	}
}

void	precision_completion(char *str, t_printf *p, int m)
{
	int	l;

	l = ft_strlen(p->buf);
	if (NUM(str[m]))
	{
		if (p->pre == 0 && p->buf[0] == '0')
			p->buf = ft_strdup("");
		else if (p->pre > l || (p->pre >= l && p->buf[0] == '-'))
		{
			if (p->buf[0] != '-')
				p->buf = str_append(og_str('0', (p->pre - l) - 1),
									p->buf, 1, 1);
			else
				p->buf = str_appendneg(og_str('0', p->pre - l), p->buf);
		}
		else if (p->width >= l && p->buf[0] == '-' && p->zero)
			p->buf = str_appendneg(og_str('0', (p->width - l) - 1), p->buf);
	}
	else if (str[m] == 's' || str[m] == 'S')
		if (p->pre < l && p->pre != -1)
			p->buf = str_cut(p->buf, p->pre);
}

void	plus_completion(char *str, t_printf *p, int m)
{
	int	l;

	l = ft_strlen(p->buf);
	if (p->plus == 1)
	{
		if (p->buf[0] != '-' &&
			(str[m] == 'd' || str[m] == 'D' || str[m] == 'i'))
		{
			if (p->zero == 1 && p->width > 0)
			{
				p->buf = str_append(og_str('0', (p->width - l) - 2),
									p->buf, 1, 1);
				p->width = 0;
			}
			p->buf = str_append("+", p->buf, 0, 1);
		}
	}
}

void	flags_completion(char *str, t_printf *p, int m)
{
	int	l;

	l = ft_strlen(p->buf);
	if (p->hash == 1)
	{
		if (p->buf[0] != '0' && p->buf[0] && (str[m] == 'x' || str[m] == 'X'))
		{
			if (p->zero == 1 && p->width > 0)
			{
				p->buf = str_append(og_str('0', (p->width - l) - 3),
									p->buf, 1, 1);
				p->width = 0;
			}
			if (str[m] == 'x')
				p->buf = str_append("0x", p->buf, 0, 1);
			else if (str[m] == 'X')
				p->buf = str_append("0X", p->buf, 0, 1);
		}
		else if (str[m] == 'o' || str[m] == 'O')
			p->buf = str_append("0", p->buf, 0, 1);
	}
}
