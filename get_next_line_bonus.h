/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:38:16 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/11/02 21:42:54 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif
# ifndef FD_MAX
#  define FD_MAX FOPEN_MAX
# endif

/* GET_NEXT_LINE */
char	*get_next_line(int fd);

/* UTILS */
size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_correct_buffer(char *buffer);
char	*ft_strjoin(char *s1, char *s2);

#endif
