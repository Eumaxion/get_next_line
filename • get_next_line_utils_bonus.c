/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   • get_next_line_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:45:38 by mlima-si          #+#    #+#             */
/*   Updated: 2025/05/06 17:25:56 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

void	*ft_memmov(char *stach)
{
	size_t	nline;
	size_t	i;

	nline = ft_strchr(stach) + 1;
	i = 0;
	while (stach[nline + i] && nline)
	{
		stach[i] = stach[i + nline];
		i++;
	}
	while (i < BUFFER_SIZE)
		stach[i++] = '\0';
}

char	*ft_strjoin(char *line, char *stach)
{
	int		i;
	int		j;
	char	*str;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	str = malloc ((ft_strlen(line) + ft_strlen(stach) + 1) * sizeof(char));
	if(str)
	{
		i = -1;
		j = -1;
		while (line[++i])
			str[i] = line[i];
		while (stach[++j])
			str[i + j] = stach [j];
		str[i + j] = '\0';		
	}
	free(line);
	return (str);
		
}

char	release(char *line, char *stach)
{
	int	i;

	if (line)
		free(line);
	i = 0;
	while (i < BUFFER_SIZE)
		stach[i++] = '\0';
	return (NULL);
}
