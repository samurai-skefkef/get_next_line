/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:49:32 by soamraou          #+#    #+#             */
/*   Updated: 2025/12/21 18:29:49 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char    *line;
	char    *tmp;
	char    c;
	int     len = 0;
	int	i;

	if (fd < 0)
		return (NULL);
	line = malloc(1);
	if (line == NULL)
		return NULL;
	while (read(fd, &c, 1) == 1)
	{
		tmp = malloc(len + 2);
		if (tmp == NULL)
			return NULL;
		i = 0;
		while (i < len)
		{
			tmp[i] = line[i];
			i++;
		}
		tmp[len++] = c;
		tmp[len] = '\0';
		free(line);
		line = tmp;
		if (c == '\n')
			break;
	}
	if (len == 0)
	{
		free(line);
		return (NULL);
	}
	return (line);
}


