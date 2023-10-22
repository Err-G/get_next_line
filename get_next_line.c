/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:44:45 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/22 22:30:36 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*temp;
	ssize_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(buffer, '\n'));
	{
		buffer[len + 1] = 0;
		temp = ft_strjoin(temp, buffer);
	}
	return (tmp);
}
