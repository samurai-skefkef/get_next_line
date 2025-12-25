/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 19:45:28 by soamraou          #+#    #+#             */
/*   Updated: 2025/12/25 14:00:16 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_stach(char *content, int fd)
{
	char	*stach;
	int		size_read;
	size_t	size_content;

	size_content = 0;
	if (content != NULL)
		size_content = ft_strlen(content);
	stach = malloc(size_content + BUFFER_SIZE + 1);
	if (stach == NULL)
	{
		free(content);
		return (NULL);
	}
	if (size_content > 0)
		ft_strlcpy(stach, content, size_content + 1);
	size_read = read(fd, stach + size_content, BUFFER_SIZE);
	if (size_read < 0)
	{
		free(stach);
		free(content);
		return (NULL);
	}
	stach[size_content + size_read] = '\0';
	free(content);
	return (stach);
}

char	*filter_getline(char *stach)
{
	char	*line;
	int		len;

	if (stach == NULL || stach[0] == '\0')
		return (NULL);
	len = 0;
	while (stach[len] != '\0' && stach[len] != '\n')
		len++;
	if (stach[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, stach, len + 1);
	return (line);
}

char	*filter_stach(char *stach, int len)
{
	char	*new_stach;
	int		i;

	if (stach[len] == '\0')
	{
		free(stach);
		return (NULL);
	}
	new_stach = malloc(ft_strlen(stach + len) + 1);
	if (new_stach == NULL)
	{
		free(stach);
		return (NULL);
	}
	i = 0;
	while (stach[len + i] != '\0')
	{
		new_stach[i] = stach[len + i];
		i++;
	}
	new_stach[i] = '\0';
	free(stach);
	return (new_stach);
}

char	*get_next_line(int fd)
{
	static char	*stach;
	char		*line;
	size_t		old_len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (stach == NULL)
		stach = ft_calloc(1, 1);
	while (stach != NULL && !ft_strchr(stach, '\n'))
	{
		old_len = ft_strlen(stach);
		stach = fill_stach(stach, fd);
		if (stach == NULL || ft_strlen(stach) == old_len)
			break ;
	}
	if (stach == NULL || stach[0] == '\0')
	{
		free(stach);
		stach = NULL;
		return (NULL);
	}
	line = filter_getline(stach);
	stach = filter_stach(stach, ft_strlen(line));
	return (line);
}
