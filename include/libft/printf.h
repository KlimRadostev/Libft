/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 19:13:25 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/04 22:44:15 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <string.h>

# define UNS(x) (x == 'u' || x == 'U')
# define INT(x) (x == 'i' || x == 'd' || x == 'D')
# define HEO(x) (x == 'x' || x == 'X' || x == 'o' || x == 'O')
# define NUM(x) (UNS(x) || HEO(x) || INT(x))
# define LET(x) (x == 'c' || x == 'S' || x == 's' || x == 'C')

typedef struct	s_printf
{
	va_list	ap;
	char	*buf;
	int		god;
	int		len;
	int		width;
	int		hash;
	int		plus;
	int		zero;
	int		pre;
	int		dot;
	int		space;
	int		key;
}				t_printf;

char			*str_append(char *s1, char *s2, int f1, int f2);
char			*str_appendneg(char *s1, char *s2);
int				ft_printf(const char *format, ...);
void			initialize_vars(t_printf *p);
uintmax_t		get_unumber(va_list arg, int len, int large);
intmax_t		get_number(va_list arg, int len, int large);
char			*ft_itoa_base(intmax_t n);
char			*ft_itoa_ubase(uintmax_t value, int base, int key);
void			parse_lag(t_printf *p);
void			print_str(char *str, t_printf *p);
void			print_char(char c, t_printf *p);
void			store_buffer2(t_printf *p, char *spec);
void			store_buffer(t_printf *p, char *spec);
int				parse_length(char *str, int max);
char			*ft_alloc(char *buf, char *str);
char			*ctos(char c);
void			parse_width(char *str, t_printf *p, int max);
void			parse_all(char *str, t_printf *p, int max);
char			*og_str(char c, int len);
char			*str_cut(char *s1, int len);
void			precision_completion(char *str, t_printf *p, int m);
void			flags_completion(char *str, t_printf *p, int m);
void			plus_completion(char *str, t_printf *p, int m);
/*
**extra functions
*/
char			*pf_strnew(size_t size);
void			*pf_memalloc(size_t size);
char			*pf_strchr(const char *s, int c);
char			*pf_strdup(const char *s1);
char			*pf_strcat(char *s1, const char *s2);
char			*pf_strcpy(char *ds1, const char *src);
char			*pf_strncpy(char *dst, const char *src, size_t len);
size_t			pf_strlen(const char *str);
int				pf_atoi(const char *str);

#endif
