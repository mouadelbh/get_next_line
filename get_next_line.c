/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:04:31 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/25 15:19:11 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlchr(char *buf)
{
	size_t i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] && buf[i] != '\n')
		i++;
	return (i);
}

// char *linemem(char *line)
// {
// 	size_t i;
// 	size_t len;
// 	char *buff;

// 	i = 0;
// 	len = ft_strlchr(line);
// 	if (ft_strchr(line, '\n'))
// 		len++;
// 	if (len == 0)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	buff = (char *)malloc(len + 1);
// 	if (!buff)
// 		return (NULL);
// 	while (line[i] && line[i] != '\n')
// 	{
// 		buff[i] = line[i];
// 		i++;
// 	}
// 	if (ft_strchr(line, '\n'))
// 		buff[i++] = '\n';
// 	buff[i] = '\0';
// 	return (buff);
// }

// char *read_buff(int fd)
// {
// 	if (!line || !line[0])
// 		return (free(buffer), free(line), NULL);
// 	return (linemem(line));
// }

char *getrest(char *s)
{
	char *p;

	int i;
	if (!s)
		return NULL;
	p = ft_substr(s, ft_strlchr(s) + 1, ft_strlen(s));

	free(s);
	return p;
}

char *get_next_line(int fd)
{
	static char *line;
	char *tmp;
	size_t rd;
	char *result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rd = read(fd, tmp, 0);
	if (rd == -1)
		return (NULL);
	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	rd = 1;
	tmp[0] = '\0';
	while (rd > 0 && !ft_strchr(tmp, '\n'))
	{
		rd = read(fd, tmp, BUFFER_SIZE);
		if (rd < 0)
		{
			free(tmp);
			free(line);
			return NULL;
		}
		tmp[rd] = '\0';
		line = ft_strjoin(line, tmp);
	}
	result = ft_substr(line, 0, ft_strlchr(line) + 1);
	line = getrest(line);
	free(tmp);
	return (result);
}
