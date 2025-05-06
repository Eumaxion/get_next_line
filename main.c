#include "get_next_line.h"

int	main(void)
{
	int	txt = open("text.txt", O_RDONLY);

	int i = ft_strlen(get_next_line(txt));
	printf(">>>>>%d", i);
	printf(">>>>>%s", get_next_line(txt));
	close(txt);
}
