/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btaha <btaha@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 02:49:41 by btaha             #+#    #+#             */
/*   Updated: 2023/01/23 02:49:42 by btaha            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_the_res(char *buffer)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen_utils(buffer) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		str[j++] = buffer[i++];
	str[j] = '\0';
	return (free(buffer), str);
}

char	*get_the_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	return (line[i] = '\0', line);
}

char	*get_the_buffer(int fd, char *buffer)
{
	char	*str;
	ssize_t	r;

	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	r = 1;
	while (!ft_strchr_utils(buffer, '\n') && r != 0)
	{
		r = read(fd, str, BUFFER_SIZE);
		if (r == -1)
			return (free(str), NULL);
		str[r] = '\0';
		buffer = ft_strjoin_utils(buffer, str);
	}
	return (free(str), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_the_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_the_line(buffer);
	buffer = get_the_res(buffer);
	return (line);
}
