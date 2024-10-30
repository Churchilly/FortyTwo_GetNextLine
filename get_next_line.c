/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:06:06 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/30 13:14:29 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

static bool	ft_next_buffer(t_line_data *d, char *buffer)
{
	char	*tmp;

	tmp = buffer;
	buffer = ft_substr(buffer, d->size);
	if (!buffer)
		return (false);
	if (tmp)
		free(tmp);
	return (true);
}

static bool	ft_get_line(t_line_data *d, char *buffer)
{
	while (buffer[d->size] && buffer[d->size] != '\n')
		d->size++;
	if (buffer[d->size] == '\n')
		d->size++;
	d->line = malloc(sizeof(char) * d->size + 1);
	if (!d->line)
		return (false);
	d->line[d->size] = '\0';
	while (d->size--)
	{
		d->line[d->size] = buffer[d->size];
	}
	return (true);
}

static	void	ft_new_buffer(char *buffer, size_t buffer_size,
					char *reader_buffer, size_t reader_buffer_size)
{
	char *tmp
}

static	bool	ft_reader(int fd, char *buffer, size_t buffer_size)
{
	char	*nl_pos;
	char	reader_buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		ret;

	ret = read(fd, reader_buffer, BUFFER_SIZE);
	reader_buffer[ret] = '\0';
	while (ret != 0 && ret != -1)
	{
		nl_pos = ft_strnl(reader_buffer);
		tmp = buffer;
		buffer = ft_strsjoin(buffer, buffer_size,
				reader_buffer, nl_pos - reader_buffer);
		printf("str: %s", reader_buffer);
		if (!buffer)
			return (false);
		free(tmp);
		if (*nl_pos == '\n')
			break ;
		ret = read(fd, reader_buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
	}
	return (ret != -1);
}

char	*get_next_line(int fd)
{
	t_line_data	d;
	static char	*buffer = NULL;
	char		*buffer_nl;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	d.line = NULL;
	d.size = 0;
	buffer_nl = ft_strnl(buffer);
	if (!fd)
		fd = STDIN_FILENO;
	if (!buffer_nl || *buffer_nl != '\n')
		if (!ft_reader(fd, buffer, buffer_nl - buffer))
			return (NULL);
	if (!ft_get_line(&d, buffer))
		return (NULL);
	if (!ft_next_buffer(&d, buffer))
		return (NULL);
	return (d.line);
}

int	main(void)
{
	get_next_line(0);
}