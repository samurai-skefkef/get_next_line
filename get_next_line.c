/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soamraou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 14:49:32 by soamraou          #+#    #+#             */
/*   Updated: 2025/12/17 20:28:52 by soamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static int	line;
	char	*str;
	size_t	len;
	int	check;

	if (fd < 0)
		return (NULL);
	if (read(fd, str, 1) == -1)
		return (NULL);
	read(fd, str, 1);
	len = 1
	while (true)
	{
		if (read(fd, str, 1) == 0)
			return (NULL);
		read(fd, str, 1);
		len++;
		if (*str == \n)
		{
			line++;
			return (str - len);
		}
		str++;
	}
}


