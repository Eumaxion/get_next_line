/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:18:36 by mlima-si          #+#    #+#             */
/*   Updated: 2025/05/02 18:42:29 by mlima-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *stat, char *buffer);
char	*set_line(char *line_buffer);

char	*get_next_line(int fd)
{
	char		*line;
	char		buf[BUFFER_SIZE +1];
	static char	*stach;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (NULL);
	stach = '\0';
	stach = read_line(fd, stach, buf);
	line = set_line(stach);
	//printf("final result: %s\n", stach);
	return (line);
}
char	*read_line(int fd, char *stat, char *buffer)
{
	int	count;
	char *temp;

	count = 1;
	temp = (malloc(BUFFER_SIZE + sizeof(char)));
	if (!temp)
		return(NULL);
	while (!ft_strchr(buffer) && count > 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		//printf("\n\nbuffer read: %s\n", buffer);
		buffer[BUFFER_SIZE +1] = '\0';
		temp = ft_strcat(temp, buffer);
		//printf("temp value after cat: %s\n", temp);
	}
	return (temp);
}
char	*set_line(char *line_buffer)
{
	size_t	len;
	char	*line;
	
	printf("\n\nstach: %s\n\n", line_buffer);
	len = ft_strchr(line_buffer);
	ft_strlcpy(line, line_buffer, len + 1);
	printf("\n\nfinal line: %s\n\n", line);
	return (line);
}

int	main(void)
{
	int txt = open("text.txt", O_RDONLY);

	get_next_line(txt);
	close(txt);
}

