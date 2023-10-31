/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:44:45 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/31 21:36:20 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	correct_buffer(char *buffer)
{
	char	*buffer_nl;
	int		len;
	int		i;

	buffer_nl = ft_strchr(buffer, '\n');
	i = 0;
	if (buffer_nl)
	{
		len = ft_strlen(buffer_nl + 1);
		while (i < len)
			buffer[i++] = buffer_nl[i + 1];
		i = 0;
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			len;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = read(fd, buffer, BUFFER_SIZE);
	while (len > 0)
	{
		line = ft_strjoin(line, buffer);
		if (ft_strchr(line, '\n'))
			break ;
		len = read(fd, buffer, BUFFER_SIZE);
	}
	if (len < 0)
	{
		if (line)
			free(line);
		return (NULL);
	}
	correct_buffer(buffer);
	return (line);
}
