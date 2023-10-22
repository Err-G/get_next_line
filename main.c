/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:56:00 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/10/22 17:17:28 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <string.h>
#include <stdio.h>

// cc -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c main.c

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDWR);
	if (fd == -1)
	{
		perror("Err: open\n");
		close(fd);
		return (1);
	}
	line = get_next_line(fd);
	printf("%s\n", line);
	free(line);
}
