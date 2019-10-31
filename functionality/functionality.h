/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionality.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 20:37:29 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:45:33 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONALITY_H
# define FUNCTIONALITY_H

# include <string.h>

void	ft_swap(void *a, void *b, size_t len);
int		ft_digitlen(int x);
int		ft_wordcountfix(const char *str, char c);
int		ft_wordcount(const char *str);
int		ft_isspace(char c);
int		ft_power(int x, int base);
int		ft_abs(int x);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_itoa(int n);

#endif
