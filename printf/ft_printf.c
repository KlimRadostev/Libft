/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:46:40 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:46:04 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "printf.h"

int		pf_atoi(const char *str)
{
	int				i;
	int				neg;
	long long int	res;

	res = 0;
	neg = 1;
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
str[i] == '\v' || str[i] == '\r' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		res *= 10;
		res += (long long int)(neg * (str[i] - 48));
		i++;
	}
	return (res);
}

char	*og_str(char c, int len)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return ((void *)0);
	i = 0;
	while (i < len + 1)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

void	initialize_vars(t_printf *p)
{
	p->width = 0;
	p->hash = 0;
	p->plus = 0;
	p->zero = 0;
	p->pre = -1;
	p->dot = 0;
	p->space = 0;
}

int		parse_spec(t_printf *p, char *str)
{
	int	i;

	i = 0;
	initialize_vars(p);
	while (str[i] && !pf_strchr("sSdDioOuUxXcCp%", str[i]))
		i++;
	if (!str[i])
		return (0);
	p->len = parse_length(str, i);
	store_buffer(p, &str[i]);
	parse_width(str, p, i);
	parse_all(str, p, i);
	precision_completion(str, p, i);
	plus_completion(str, p, i);
	flags_completion(str, p, i);
	if (p->space && !p->plus && p->buf[0] != '-'
		&& (str[i] == 'd' || str[i] == 'D' || str[i] == 'i'))
		p->buf = str_append(" ", p->buf, 0, 1);
	print_str(p->buf, p);
	(p->buf) ? free(p->buf) : 0;
	return (i);
}

int		ft_printf(const char *format, ...)
{
	t_printf	*p;
	int			tmp;
	int			i;

	if (!(p = (t_printf *)pf_memalloc(sizeof(t_printf) * 1)))
		return (0);
	i = 0;
	p->god = 0;
	p->key = 0;
	va_start(p->ap, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			i += parse_spec(p, (char *)&format[i]);
		}
		else
			print_char(format[i], p);
		i++;
	}
	va_end(p->ap);
	tmp = p->god;
	free(p);
	return (tmp);
}
