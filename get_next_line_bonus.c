/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:14:52 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/25 13:39:51 by mel-bouh         ###   ########.fr       */
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

char	*linemem(char *line)
{
	size_t	i;
	size_t	len;
	char	*buff;

	i = 0;
	len = ft_strlchr(line);
	if (ft_strchr(line, '\n'))
		len++;
	if (len == 0)
	{
		free (line);
		return (NULL);
	}
	buff = (char *)malloc(len + 1);
	if (!buff)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		buff[i] = line[i];
		i++;
	}
	if (ft_strchr(line, '\n'))
		buff[i++] = '\n';
	buff[i] = '\0';
	return (buff);
}

char	*creatline(char *line, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(line, buffer);
	free (line);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*read_buff(int fd, char **line)
{
	char		*buffer;
	char		*buf;
	char		*tmp;
	size_t		rd;

	tmp = NULL;
	if (!ft_strchr(line[fd], '\n'))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (NULL);
		rd = read(fd, buffer, BUFFER_SIZE);
		while (rd > 0)
		{
			buffer[rd] = '\0';
			line[fd] = creatline(line[fd], buffer);
			if (ft_strchr(line[fd], '\n'))
				break ;
			rd = read(fd, buffer, BUFFER_SIZE);
		}
	}
	if (!line[fd] || !line[fd][0])
		return (free (line[fd]), NULL);
	buf = linemem(line[fd]);
	tmp = line[fd];
	free (buffer);
	line[fd] = ft_substr(line[fd], ft_strlchr(line[fd]) + 1);
	return (free(tmp), buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_buff(fd, buffer);
	return (line);
}
