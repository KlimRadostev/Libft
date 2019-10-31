/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:01:43 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:46:35 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "hash.h"
#include "../printf/printf.h"
#include "../strlib/strlib.h"

unsigned int		g_m[64];
unsigned int		g_k[64] = {
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5,
	0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3,
	0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc,
	0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
	0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13,
	0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3,
	0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5,
	0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208,
	0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2};

static unsigned int	sha256_rot(unsigned int num, unsigned int rot)
{
	unsigned int	i;
	unsigned int	r;

	i = 0;
	while (i < rot)
	{
		r = num & 1;
		num = num >> 1;
		num += r << 31;
		i++;
	}
	return (num);
}

static void			sha256_init(t_sha256 *t, unsigned char *str)
{
	t->ao = 0x6a09e667;
	t->bo = 0xbb67ae85;
	t->co = 0x3c6ef372;
	t->doo = 0xa54ff53a;
	t->eo = 0x510e527f;
	t->fo = 0x9b05688c;
	t->go = 0x1f83d9ab;
	t->ho = 0x5be0cd19;
	t->out_len = find_length(str);
	t->out = (unsigned char*)ft_strnew(t->out_len);
	ft_strcpy((char *)t->out, (char *)str);
	t->len = ft_strlen((char *)str) * 8;
	t->out[ft_strlen((char *)str)] = 1 << 7;
	t->i = 0;
	while (t->i < 8)
	{
		t->out[t->out_len - 8 + t->i] = ((unsigned char *)&(t->len))[7 - t->i];
		t->i++;
	}
	t->i = 0;
}

static void			sha256_setup(t_sha256 *t)
{
	t->x = 0;
	while (t->x < 16)
	{
		g_m[t->x] = 0;
		g_m[t->x] += t->out[t->i * 64 + t->x * 4 + 0] << 24;
		g_m[t->x] += t->out[t->i * 64 + t->x * 4 + 1] << 16;
		g_m[t->x] += t->out[t->i * 64 + t->x * 4 + 2] << 8;
		g_m[t->x] += t->out[t->i * 64 + t->x * 4 + 3] << 0;
		t->x++;
	}
	while (t->x < 64)
	{
		t->s0 = sha256_rot(g_m[t->x - 15], 7) ^ sha256_rot(g_m[t->x - 15],
18) ^ (g_m[t->x - 15] >> 3);
		t->s1 = sha256_rot(g_m[t->x - 2], 17) ^ sha256_rot(g_m[t->x - 2],
19) ^ (g_m[t->x - 2] >> 10);
		g_m[t->x] = g_m[t->x - 16] + t->s0 + g_m[t->x - 7] + t->s1;
		t->x++;
	}
	t->a = t->ao;
	t->b = t->bo;
	t->c = t->co;
	t->d = t->doo;
}

static void			sha256_mainloop(t_sha256 *t)
{
	t->j = 0;
	while (t->j < 64)
	{
		t->s1 = sha256_rot(t->e, 6) ^ sha256_rot(t->e,
11) ^ sha256_rot(t->e, 25);
		t->ch = (t->e & t->f) ^ ((~t->e) & t->g);
		t->tmp1 = t->h + t->s1 + t->ch + g_k[t->j] + g_m[t->j];
		t->s0 = sha256_rot(t->a, 2) ^ sha256_rot(t->a,
13) ^ sha256_rot(t->a, 22);
		t->maj = (t->a & t->b) ^ (t->a & t->c) ^ (t->b & t->c);
		t->tmp2 = t->s0 + t->maj;
		t->h = t->g;
		t->g = t->f;
		t->f = t->e;
		t->e = t->d + t->tmp1;
		t->d = t->c;
		t->c = t->b;
		t->b = t->a;
		t->a = t->tmp1 + t->tmp2;
		t->j++;
	}
}

void				ft_sha256(unsigned char *str)
{
	t_sha256 t;

	sha256_init(&t, str);
	while (t.i < (t.out_len * 8) / 512)
	{
		sha256_setup(&t);
		t.e = t.eo;
		t.f = t.fo;
		t.g = t.go;
		t.h = t.ho;
		sha256_mainloop(&t);
		t.ao = t.ao + t.a;
		t.bo = t.bo + t.b;
		t.co = t.co + t.c;
		t.doo = t.doo + t.d;
		t.eo = t.eo + t.e;
		t.fo = t.fo + t.f;
		t.go = t.go + t.g;
		t.ho = t.ho + t.h;
		t.i++;
	}
	ft_printf("%.8x%.8x%.8x%.8x%.8x%.8x%.8x%.8x", t.ao, t.bo,
t.co, t.doo, t.eo, t.fo, t.go, t.ho);
	free(t.out);
}
