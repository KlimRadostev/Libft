/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kradoste <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 16:55:50 by kradoste          #+#    #+#             */
/*   Updated: 2018/06/01 15:00:11 by kradoste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	determine_line(char **str, char **line)
{
	char	*tmp;

	if ((*str)[0] == '\0')
		return (0);
	if (ft_strchr(*str, '\n') && !(*(ft_strchr(*str, '\n')) = '\0'))
	{
		*line = ft_strdup(*str);
		tmp = ft_strdup(ft_strchr(*str, '\0') + 1);
		free(*str);
		*str = tmp;
	}
	else
	{
		*line = ft_strdup(*str);
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
	(!(str[fd])) && (str[fd] = ft_strnew(0));
	while (!ft_strchr(str[fd], '\n') && (br = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[br] = '\0';
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = ft_strdup(tmp);
		free(tmp);
	}
	return (determine_line(&str[fd], line));
}
