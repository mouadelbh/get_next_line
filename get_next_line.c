/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:04:31 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/25 09:54:42 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*read_buff(int fd)
{
	static char	*line;
	char		*tmp;
	char		*buf;
	char		buffer[BUFFER_SIZE + 1];
	size_t		rd;

	tmp = NULL;
	if (!ft_strchr(line, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		while (rd > 0)
		{
			buffer[rd] = '\0';
			line = creatline(line, buffer);
			if (ft_strchr(line, '\n'))
				break ;
			rd = read(fd, buffer, BUFFER_SIZE);
		}
	}
	if (!line || !line[0])
		return (free (line), NULL);
	buf = linemem(line);
	tmp = line;
	line = ft_substr(line, ft_strlchr(line) + 1, ft_strlen(line) + 1);
	return (free(tmp), buf);
}

char	*get_next_line(int fd)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > UINT_MAX)
		return (NULL);
	line = read_buff(fd);
	return (line);
}
