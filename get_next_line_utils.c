/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 00:57:11 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/30 11:24:47 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>

static bool	ft_strncpy(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*ft_strsjoin(char *s1, size_t size1, char *s2, size_t size2)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!res)
		return (NULL);
	ft_strncpy(res, s1, size1);
	ft_strncpy(&res[size1], s2, size2);
	if (s1)
		free(s1);
	return (res);
}

char	*ft_strnl(char *str)
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

char	*ft_substr(char const *str, unsigned int start)
{
	char	*sub;
	size_t	sub_len;

	sub_len = 0;
	while (*(str + start + sub_len))
		sub_len++;
	sub = malloc(sizeof(char) * (sub_len + 1));
	if (!sub)
		return (NULL);
	while (*(str + start++))
		*(sub)++ = *(str + start);
	return (sub);
}