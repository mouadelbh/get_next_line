/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:06:32 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/25 16:51:44 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *line, char *buf);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlchr(char *buf);
size_t	ft_strlen(char *str);
size_t	ft_strchr(char	*buf, char c);

#endif
