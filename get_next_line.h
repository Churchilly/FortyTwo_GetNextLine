/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusudemi <yusudemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:10:15 by yusudemi          #+#    #+#             */
/*   Updated: 2024/10/30 13:07:31 by yusudemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1	
# endif

# include <stddef.h>
// debug
# include <stdio.h>

typedef struct s_line_data
{
	char	*line;
	size_t	size;
}	t_line_data;

char	*get_next_line(int fd);
char	*ft_strsjoin(char *s1, size_t size1, char *s2, size_t size2);
char	*ft_strnl(char *str);
char	*ft_substr(char const *str, unsigned int start);

#endif