/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:55:50 by kradoste          #+#    #+#             */
/*   Updated: 2019/10/31 01:51:29 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include "get_next_line.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s != c && *s)
		s++;
	if (*s == c)
		return ((char *)s);
	return ((void *)0);
}

static void	ft_memdel(void **ap)
{
	if (!ap || !*ap)
		return ;
	free(*ap);
	*ap = (void *)0;
}

static int	determine_line(char **str, char **line)
{
	char	*tmp;

	if ((*str)[0] == '\0')
		return (0);
	if (ft_strchr(*str, '\n') && !(*(ft_strchr(*str, '\n')) = '\0'))
	{
		*line = gnl_strdup(*str);
		tmp = gnl_strdup(ft_strchr(*str, '\0') + 1);
		free(*str);
		*str = tmp;
	}
	else
	{
		*line = gnl_strdup(*str);
		ft_memdel((void **)str);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int			br;
	char		buffer[BUFF_SIZE + 1];
	static char	*str[5000];
	char		*tmp;

	if (fd == -1 || read(fd, buffer, 0) < 0 || !line)
		return (-1);
	(!(str[fd])) && (str[fd] = gnl_strnew(0));
	while (!ft_strchr(str[fd], '\n') && (br = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[br] = '\0';
		tmp = gnl_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = gnl_strdup(tmp);
		free(tmp);
	}
	return (determine_line(&str[fd], line));
}
