/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:47:30 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/09 02:39:04 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

void	*ft_free(char *buffer)
{
	char	*p;

	p = buffer;
	if (buffer)
	{
		while (*p)
			*p++ = 0;
		free(buffer);
	}
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	char	*p;

	if (!str)
		return (0);
	p = str;
	while (*p)
		p++;
	return (p - str);
}

char	*ft_strnl(char	*str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == '\n')
			return (str);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *buffer, size_t buffer_len,
					char *reader_buffer, size_t reader_buffer_size)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = malloc(sizeof(char) * (buffer_len + reader_buffer_size + 1));
	if (!res)
		return (ft_free(buffer));
	i = 0;
	while (i < buffer_len)
	{
		res[i] = buffer[i];
		i++;
	}
	j = 0;
	while (j < reader_buffer_size)
	{
		res[i + j] = reader_buffer[j];
		j++;
	}
	res[i + j] = '\0';
	ft_free(buffer);
	return (res);
}

char	*ft_substr(char *str, size_t start)
{
	char	*res;
	char	*p;
	size_t	res_len;

	if (*(str + start) == '\0')
		return (NULL);
	res_len = ft_strlen((str + start));
	res = malloc(sizeof(char) * (res_len + 1));
	if (!res)
		return (NULL);
	p = res;
	while (*(str + start))
	{
		*p = *(str + start);
		start++;
		p++;
	}
	*p = '\0';
	return (res);
}
