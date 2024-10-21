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

#ifndef _LIBFT_UTIL_H_
#define _LIBFT_UTIL_H_

#define FT_ABS(x) (((x) < 0) ? -(x) : (x))
#define FT_SWAP_END(x) (((((x) >> 24) & 0x000000FF) | (((x) << 8) & 0x00FF0000) | (((x) >> 8) & 0x0000FF00) | (((x) << 24) & 0xFF000000)))

#define FT_ISSPACE(c) (((((c) > 8) && ((c) < 14)) || ((c) == ' ')) ? true : false)
#define FT_ISASCII(c) ((((c) >= 0) && ((c) <= 127)) ? true : false)
#define FT_ISPRINT(c) ((((c) > 31) && ((c) < 127)) ? true : false)
#define FT_ISDIGIT(c) ((((c) > 47) && ((c) < 58)) ? true : false)
#define FT_ISUPPER(c) ((((c) > 64) && ((c) < 91)) ? true : false)
#define FT_ISLOWER(c) ((((c) > 96) && ((c) < 123)) ? true : false)
#define FT_LOWER(c) (FT_ISLOWER(c) ? ((c) + 32) : (c))
#define FT_UPPER(c) (FT_ISUPPER(c) ? ((c) - 32) : (c))
#define FT_ISALPHA(c) ((FT_ISLOWER(c) || FT_ISUPPER(c)) ? true : false)
#define FT_ISALNUM(c) ((FT_ISALPHA(c) || FT_ISDIGIT(c)) ? true : false)

void	ft_swap(void *a, void *b, size_t len);
int		ft_digitlen(int x);
int		ft_wordcountfix(const char *str, char c);
int		ft_wordcount(const char *str);
int		ft_power(int x, int base);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);

#endif /* _LIBFT_UTIL_H_ */
