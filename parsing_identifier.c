/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_identifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 15:10:57 by kradoste          #+#    #+#             */
/*   Updated: 2018/11/06 12:10:21 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ctos(char c)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return ((void *)0);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_alloc(char *buf, char *str)
{
	int	len;

	if (str)
	{
		len = 0;
		while (str[len])
			len++;
		if (!(buf = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		len = -1;
		while (str[++len])
			buf[len] = str[len];
		buf[len] = str[len];
		return (buf);
	}
	else
		return (NULL);
}

int		parse_length(char *str, int max)
{
	int	i;

	i = 0;
	while (str[i] && i < max && !ft_strchr("hljz", str[i]))
		i++;
	if (str[i] == 'h' && str[i + 1] == 'h')
		return (1);
	else if (str[i] == 'h')
		return (2);
	else if (str[i] == 'l' && str[i + 1] == 'l')
		return (3);
	else if (str[i] == 'l')
		return (4);
	else if (str[i] == 'j')
		return (5);
	else if (str[i] == 'z')
		return (6);
	return (0);
}

void	store_buffer2(t_printf *p, char *spec)
{
	if (*spec == 'c' || *spec == 'C')
	{
		p->buf = ctos(va_arg(p->ap, int));
		(p->buf[0] == 0) && (p->key = 1);
	}
	(*spec == '%') && (p->buf = ft_strdup("%"));
	if (*spec == 'p')
	{
		p->buf = ft_itoa_ubase((long)(va_arg(p->ap, void*)), 16, 0);
		p->buf = str_append("0x", p->buf, 0, 1);
	}
	if (*spec == 's' || *spec == 'S')
	{
		if (!(p->buf = ft_alloc(p->buf, va_arg(p->ap, char *))))
			p->buf = ft_strdup("(null)");
	}
}

void	store_buffer(t_printf *p, char *spec)
{
	intmax_t	value;
	uintmax_t	valor;

	if (LET(*spec) || *spec == 'p' || *spec == '%')
		store_buffer2(p, spec);
	else
	{
		if (*spec == 'd' || *spec == 'D' || *spec == 'i')
		{
			value = (*spec == 'D') ?
				get_number(p->ap, p->len, 1) : get_number(p->ap, p->len, 0);
			p->buf = ft_itoa_base(value);
		}
		else
		{
			valor = (*spec == 'U') ? get_unumber(p->ap, p->len, 1)
				: get_unumber(p->ap, p->len, 0);
			(*spec == 'o' || *spec == 'O')
				&& (p->buf = ft_itoa_ubase(valor, 8, 0));
			(*spec == 'u' || *spec == 'U')
				&& (p->buf = ft_itoa_ubase(valor, 10, 0));
			(*spec == 'x') && (p->buf = ft_itoa_ubase(valor, 16, 0));
			(*spec == 'X') && (p->buf = ft_itoa_ubase(valor, 16, 1));
		}
	}
}
