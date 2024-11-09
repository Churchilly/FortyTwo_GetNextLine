/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:47:23 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/09 03:00:59 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static char	*ft_next_buffer(char *buffer, char *line)
{
	char	*nxt;
	size_t	line_len;

	if (!line)
		return (ft_free(buffer));
	if (!buffer)
		return (NULL);
	line_len = ft_strlen(line);
	nxt = ft_substr(buffer, line_len);
	ft_free(buffer);
	if (!nxt)
		return (NULL);
	return (nxt);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	size_t	size;

	size = 0;
	while (buffer[size] && buffer[size] != '\n')
		size++;
	if (buffer[size] == '\n')
		size++;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (ft_free(buffer));
	line[size] = '\0';
	while (size--)
		line[size] = buffer[size];
	return (line);
}

static char	*ft_reader(int fd, char *buffer, size_t buffer_len)
{
	char	reader_buffer[BUFFER_SIZE + 1];
	char	*reader_nl;
	int		ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, reader_buffer, BUFFER_SIZE);
		if (ret == -1)
			return (ft_free(buffer));
		reader_buffer[ret] = '\0';
		buffer = ft_strjoin(buffer, buffer_len, reader_buffer, ret);
		if (!buffer)
			return (NULL);
		buffer_len += ret;
		reader_nl = ft_strnl(reader_buffer);
		if (*reader_nl == '\n')
			return (buffer);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*buffer_nl;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (ft_free(buffer[fd]), buffer[fd] = NULL);
	if (!(buffer[fd]))
	{
		buffer[fd] = malloc(sizeof(char) * 1);
		if (!(buffer[fd]))
			return (NULL);
		*buffer[fd] = '\0';
	}
	buffer_nl = ft_strnl(buffer[fd]);
	if (!buffer_nl || *buffer_nl != '\n')
		buffer[fd] = ft_reader(fd, buffer[fd], buffer_nl - buffer[fd]);
	if (!(buffer[fd]))
		return (NULL);
	if (!(*(buffer[fd])))
		return (ft_free(buffer[fd]), buffer[fd] = NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_next_buffer(buffer[fd], line);
	return (line);
}
