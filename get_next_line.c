/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:44:45 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/22 17:20:24 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	correct_new_line(ssize_t len, char **buff)
{
	char	*new_line_pos;

	new_line_pos = ft_strchr(*buff, '\n');
	if (new_line_pos)
	{
		*buff = ft_substr(*buff, 0, (new_line_pos - *buff));
		return (1);
	}
	else if (len < BUFFER_SIZE)
	{
		*buff = ft_substr(*buff, 0, len);
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*tmp;
	ssize_t		len;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	len = read(fd, tmp, BUFFER_SIZE);
	while (len > 0)
	{
		tmp[len] = 0;
		if (correct_new_line(len, &tmp))
			break ;
		buff = ft_strjoin(buff, tmp);
		len = read(fd, tmp, BUFFER_SIZE);
	}
	if (len < 0 || (len == 0 && !*buff))
	{
		free(buff);
		return (NULL);
	}
	free(tmp);
	return (buff);
}
