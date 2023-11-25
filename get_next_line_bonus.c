/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:14:52 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/25 18:49:31 by mel-bouh         ###   ########.fr       */
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
		return (NULL);
	return (free(s), p);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*tmp;
	char		*result;
	size_t		rd;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, tmp, 0) < 0)
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
			return (free(tmp), free(line[fd]), NULL);
		tmp[rd] = '\0';
		line[fd] = ft_strjoin(line[fd], tmp);
	}
	if (!line[fd] || !line[fd][0])
		return (free(tmp), NULL);
	result = ft_substr(line[fd], 0, ft_strlchr(line[fd]) + 1);
	line[fd] = getrest(line[fd]);
	return (free(tmp), result);
}
