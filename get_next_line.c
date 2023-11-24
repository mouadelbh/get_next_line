/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:04:31 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/24 17:19:57 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*read_buff(int fd)
{
	static char	*line;
	char		*tmp;
	char		*buf;
	char		*buffer;
	size_t		rd;

	buffer = (char *)malloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	while ((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[rd] = '\0';
		tmp = ft_strjoin(line, buffer);
		if (!tmp)
		{
			free (line);
			free (buffer);
			return (NULL);
		}
		if (line)
			free (line);
		line = tmp;
		if (ft_strchr(line, '\n'))
			break ;
	}
	buf = linemem(line);
	line = ft_substr(line, ft_strlchr(line) + 1, ft_strlen(line));
	free (buffer);
	return (buf);
}

char	*get_next_line(int fd)
{
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_buff(fd);
	return (line);
}
