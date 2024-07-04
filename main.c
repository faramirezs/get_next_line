#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int  fd;
	char *line;
	int  count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1) {
		printf("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd))!= NULL)
	{
/* 		line = get_next_line(fd);
		if (line == NULL)
			break ; */
		count++;
		printf("get_next_line execution #[%d]:%s\n", count, line);
		free(line);
		line = NULL;
 	}
 close(fd);
 get_next_line(-1);
 return (0);
}
