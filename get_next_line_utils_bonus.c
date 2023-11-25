/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 09:14:24 by mel-bouh          #+#    #+#             */
/*   Updated: 2023/11/25 09:51:00 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strchr(char *buf, char c)
{
	size_t	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == c)
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start)
{
	char	*sub;
	size_t	len;
	size_t	length;
	size_t	i;

	if (!s)
		return (NULL);
	length = ft_strlen(s);
	i = 0;
	if (start > length)
		len = 0;
	len = length - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	s = s + start;
	*(sub + len) = '\0';
	while (len-- && *s)
	{
		*(sub + i) = *(s + i);
		i++;
	}
	return (sub);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char *line, char *buf)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!line)
		return (ft_strdup(buf));
	join = (char *)malloc(ft_strlen(line) + ft_strlen(buf) + 1);
	if (!join)
		return (NULL);
	while (line[i])
		join[j++] = line[i++];
	i = 0;
	while (buf[i])
		join[j++] = buf[i++];
	join[j] = '\0';
	return (join);
}
