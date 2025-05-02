#include "get_next_line.h"
#include <stdio.h>

char	*get_test(int fd)
{
	size_t		nRead;
	char		buf[BUFFER_SIZE + 1];
	if (fd != -1)
	{
		nRead = read(fd, buf, BUFFER_SIZE);
		while (nRead > 0)
		{
			buf[BUFFER_SIZE + 1] = '\0';
			printf("%s", buf);
			printf("%s", "|");
			nRead = read(fd, buf, BUFFER_SIZE);
		} 
	}
	else
		return (NULL);
}
/* 
int	main(void)
{
	int txt = open("text.txt", O_RDONLY);
	get_next_line(txt);
	close(txt);
} */