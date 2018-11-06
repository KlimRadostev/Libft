/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 21:24:35 by kradoste          #+#    #+#             */
/*   Updated: 2018/11/06 12:10:30 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_append(char *s1, char *s2, int f1, int f2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return ((void *)0);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	if (f1)
		free(s1);
	if (f2)
		free(s2);
	return (str);
}

char	*str_appendneg(char *s1, char *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (ft_strdup(""));
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return ((void *)0);
	ft_strcpy(str, s1);
	ft_strcat(str, &s2[1]);
	free(s1);
	free(s2);
	return (str_append("-", str, 0, 1));
}

char	*str_cut(char *s1, int len)
{
	char	*str;

	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	ft_strncpy(str, s1, len);
	free(s1);
	return (str);
}

void	print_char(char c, t_printf *p)
{
	p->god++;
	write(1, &c, 1);
}

void	print_str(char *str, t_printf *p)
{
	int	i;
	int	l;
	int	key;

	key = p->key;
	i = 0;
	l = ft_strlen(str);
	while (p->width > (l + p->key))
	{
		(p->zero && !p->dot) ? (print_char('0', p)) : (print_char(' ', p));
		p->width--;
	}
	if (str[i] || p->key)
		while (str[i] || p->key)
		{
			(p->key) && (p->key = 0);
			print_char(str[i++], p);
		}
	if (p->width < 0)
		while (p->width < (l * -1) - key)
		{
			print_char(' ', p);
			p->width++;
		}
}
