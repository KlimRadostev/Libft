/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:34:02 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/29 23:59:29 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_H
# define HASH_H

typedef struct	s_md5
{
	unsigned int	a0;
	unsigned int	b0;
	unsigned int	c0;
	unsigned int	d0;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	x;
	unsigned int	y;
	unsigned int	out_len;
	long long		len;
	unsigned int	f;
	unsigned int	g;
	unsigned char	*out;
	unsigned int	var[16];
}				t_md5;

typedef struct	s_sha256
{
	unsigned int	ao;
	unsigned int	bo;
	unsigned int	co;
	unsigned int	doo;
	unsigned int	eo;
	unsigned int	fo;
	unsigned int	go;
	unsigned int	ho;
	unsigned int	i;
	long long		len;
	unsigned int	out_len;
	unsigned char	*out;
	unsigned int	x;
	unsigned int	s0;
	unsigned int	s1;
	unsigned int	ch;
	unsigned int	maj;
	unsigned int	tmp1;
	unsigned int	tmp2;
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;
	unsigned int	d;
	unsigned int	e;
	unsigned int	f;
	unsigned int	g;
	unsigned int	h;
	unsigned int	j;
}				t_sha256;

void			ft_sha256(unsigned char *str);
void			ft_md5(unsigned char *str);
int				find_length(unsigned char *str);
int				swap_end(int n);

#endif
