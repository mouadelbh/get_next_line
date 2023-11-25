/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:04:31 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/25 16:16:09 by mel-bouh         ###   ########.fr       */
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

char	*getrest(char *s)
{
	char	*p;

	p = ft_substr(s, ft_strlchr(s) + 1, ft_strlen(s));
	if (!p)
		return (NULL);
	return (free(s), p);
}

size_t	check(int fd)
{
	char	*tmp;
	size_t	rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (1);
	rd = read(fd, tmp, 0);
	if (rd < 0)
		return (1);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*tmp;
	char		*result;
	size_t		rd;

	if (check(fd))
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
			return (free(tmp), free(line), NULL);
		tmp[rd] = '\0';
		line = ft_strjoin(line, tmp);
	}
	if (!line || !line[0])
		return (free(tmp), NULL);
	result = ft_substr(line, 0, ft_strlchr(line) + 1);
	line = getrest(line);
	return (free(tmp), result);
}
