/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_in_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 18:19:11 by kradoste          #+#    #+#             */
/*   Updated: 2018/11/06 12:10:06 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		get_number(va_list arg, int len, int large)
{
	intmax_t	val;

	if (len == 3)
		return (va_arg(arg, long long));
	else if (len == 4)
		return (va_arg(arg, long));
	else if (len == 5)
		return (va_arg(arg, intmax_t));
	else if (len == 6)
		return (va_arg(arg, size_t));
	val = (large) ? va_arg(arg, long) : va_arg(arg, int);
	if (!large)
	{
		if (len == 0)
			val = (int)val;
		else if (len == 1)
			val = (char)val;
		else if (len == 2)
			val = (short)val;
	}
	return (val);
}

static size_t	ft_get_len(intmax_t n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa_base(intmax_t n)
{
	char		*str;
	size_t		len;
	intmax_t	tmp;

	if ((uintmax_t)n == -9223372036854775808ULL)
		return (ft_strdup("-9223372036854775808"));
	len = ft_get_len(n);
	tmp = n;
	if (n < 0)
	{
		tmp = -n;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str[--len] = tmp % 10 + '0';
	while (tmp /= 10)
		str[--len] = tmp % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}

uintmax_t		get_unumber(va_list arg, int len, int large)
{
	uintmax_t	val;

	if (len == 3)
		return (va_arg(arg, unsigned long long));
	else if (len == 4)
		return (va_arg(arg, unsigned long));
	else if (len == 5)
		return (va_arg(arg, uintmax_t));
	if (len == 6)
		return (va_arg(arg, size_t));
	val = (large) ? va_arg(arg, unsigned long) : va_arg(arg, unsigned int);
	if (!large)
	{
		if (len == 0)
			val = (unsigned int)val;
		else if (len == 1)
			val = (unsigned char)val;
		else if (len == 2)
			val = (unsigned short)val;
	}
	return (val);
}

char			*ft_itoa_ubase(uintmax_t value, int base, int key)
{
	char		*s;
	uintmax_t	n;
	int			i;

	n = value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i--)
	{
		if (key == 1)
			s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		else
			s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}
