#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		printf("get_next_line execution #[%d]:%s\n", count, line);
		free(line);
		line = NULL;
	}
	close(fd);
	get_next_line(-1);
	return (0);
}
