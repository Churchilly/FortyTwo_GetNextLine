/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:47:53 by yusudemi          #+#    #+#             */
/*   Updated: 2024/11/09 02:39:01 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define OPEN_MAX 65534

# include <stddef.h>
# include <stdio.h>

char	*get_next_line(int fd);
void	*ft_free(char *buffer);
size_t	ft_strlen(char *str);
char	*ft_strnl(char	*str);
char	*ft_strjoin(char *buffer, size_t buffer_len,
			char *reader_buffer, size_t reader_buffer_size);
char	*ft_substr(char *str, size_t start);

#endif
