/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getNextLine.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 18:53:54 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:50:03 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <string.h>

int		get_next_line(const int fd, char **line);
char	*gnl_strnew(size_t size);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*gnl_strdup(const char *s1);

#endif
