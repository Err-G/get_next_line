/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 21:21:08 by ecarvalh          #+#    #+#             */
/*   Updated: 2023/11/02 18:02:52 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(char *str, int c)
{
	while (*str)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	ret = (void *)malloc(nmemb * size);
	if (ret)
	{
		auto size_t i = 0;
		while (i < nmemb * size)
			*((unsigned char *)ret + i++) = 0;
	}
	return (ret);
}

void	correct_buffer(char *buffer)
{
	char	*buffer_nl;
	int		i;
	int		len;

	buffer_nl = ft_strchr(buffer, '\n');
	i = 0;
	if (buffer_nl)
	{
		len = ft_strlen(buffer_nl + 1);
		while (i < len)
		{
			buffer[i] = buffer_nl[i + 1];
			i++;
		}
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
	}
	else
	{
		while (i < BUFFER_SIZE)
			buffer[i++] = 0;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	auto char *str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	auto size_t i = (size_t)-1;
	auto size_t j = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	str[i] = s2[j];
	if (s2[j] == '\n')
		str[++i] = '\0';
	correct_buffer(s2);
	free(s1);
	return (str);
}
