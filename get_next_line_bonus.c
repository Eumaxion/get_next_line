/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:33:22 by mlima-si          #+#    #+#             */
/*   Updated: 2025/05/06 17:33:54 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line_bonus(int fd)
{
	char		*line;
	static char	stach[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (stach[0])
		line = ft_strjoin(line, stach);
	if (ft_strchr(stach) >= 0)
		return (set_line(line, stach));
	line = get_line(line, stach, fd);
	if (!line)
		return (NULL);
	line = set_line(line, stach);
	return (line);
}

char	*get_line(char *line, char *stach, int fd)
{
	size_t	counter;

	ft_memmov(stach);
	while(1)
	{
		counter = read(fd, stach, BUFFER_SIZE);
		if (counter < 0)
			return (release(line, stach));
		if (counter == 0)
			break ;
		line = ft_strjoin(line, stach);
		if (!line)
			return (NULL);
		if (ft_strchr(stach) >= 0)
			break ;
		ft_memmov(stach);
	}
	return (line);
}

char	*set_line(char *line, char *stach)
{
	int	nline;

	nline = ft_strchr(line);
	if (nline >= 0)
		line[nline + 1] = '\0';
	ft_memmov(stach);
	return (nline);
}
