/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:14:52 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/26 15:08:41 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlchr(char *buf)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

char	*getrest(char *s)
{
	char	*p;

	p = ft_substr(s, ft_strlchr(s) + 1, ft_strlen(s));
	if (!p)
		return (free(s), NULL);
	return (free(s), p);
}

char	*join(int fd, char *line, char *tmp, long *rd)
{
	*rd = read(fd, tmp, BUFFER_SIZE);
	if (*rd < 0)
		return (free(tmp), free(line), NULL);
	tmp[*rd] = '\0';
	line = ft_strjoin(line, tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*tmp;
	char		*result;
	ssize_t		rd;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	tmp = (char *)malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (free(line[fd]), NULL);
	if (read(fd, tmp, 0) < 0)
		return (free(tmp), NULL);
	rd = 1;
	tmp[0] = '\0';
	while (rd > 0 && !ft_strchr(tmp, '\n'))
		line[fd] = join(fd, line[fd], tmp, &rd);
	if (!line[fd] || !line[fd][0])
		return (free(tmp), NULL);
	result = ft_substr(line[fd], 0, ft_strlchr(line[fd]) + 1);
	line[fd] = getrest(line[fd]);
	return (free(tmp), result);
}
