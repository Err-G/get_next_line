/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:44:45 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/11/02 22:03:57 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buffer[FD_MAX][BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	auto int len = 1;
	if (!buffer[fd][0])
		len = read(fd, buffer[fd], BUFFER_SIZE);
	while (len > 0)
	{
		line = ft_strjoin(line, buffer[fd]);
		if (ft_strchr(line, '\n'))
			break ;
		len = read(fd, buffer[fd], BUFFER_SIZE);
	}
	if (len < 0)
	{
		if (line)
			free(line);
		return (NULL);
	}
	return (line);
}
