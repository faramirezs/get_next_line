#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"


char *append_buffer (char *big_buffer, char *b2)
{
	char *temp;

	temp = ft_strjoin(big_buffer, b2);
	if (temp == NULL)
	{
		printf("ft_strjoin failed\n");
		return(NULL);
	}
	free(big_buffer);
	return(temp);
}

char *extract_line (char * big_buffer)
{
	char * nl_char;
	char * line;
/*
	int	i;

	i = 0;
	fprintf(stderr, "big_buffer: %s\n", big_buffer);
	while(big_buffer[i] != '\n' && big_buffer[i] != '\0')
		i++;
	fprintf(stderr, "i: %i\n", i); */

	nl_char = ft_calloc(1, sizeof(char));
	line = ft_calloc(1, sizeof(char));

	 if (nl_char == NULL || line == NULL) {
	 	printf("Memory allocation failed at extract_line()\n");
	 	return(NULL);
	}
	else if (ft_strchr(big_buffer, '\n') != NULL)
	{
		nl_char = ft_strchr(big_buffer, '\n');
		line = ft_substr(big_buffer, 0, nl_char - big_buffer);
		//printf("Line from extract_line():%s\n", line);
		//free(nl_char);
		//nl_char = NULL;
		return(line);
	}
	else
	{
		// if(line)
		free(line);
		free(nl_char);

		return(0);
	}

}

char *obtain_remaining (char *big_buffer, char *line){

	if (ft_strcmp(big_buffer, line)==0)
	{
		//printf("big_buffer and line are equal: big_buffer:%s and line: %s\n", big_buffer, line);
		free(big_buffer);
		//printf("Return equal cero from obtain_remaining");
        return(0);
    }
    else
    {
        big_buffer = ft_substr(big_buffer, ft_strlen(line) + 1, ft_strlen(big_buffer));
        //printf("Remaining after removing line: %s\n", big_buffer);
        return(big_buffer);
    }
}

char *read_file (char *big_buffer, int fd) {
	int r_bytes;
	char * buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL) {
		printf("Memory allocation failed\n");
		return(NULL);
	}
	r_bytes = 1;
	while(r_bytes > 0){
		r_bytes = read(fd, buffer, BUFFER_SIZE);
		if (r_bytes == -1)
		{
			printf("Read error");
			return (free(buffer), NULL);
		}
		else if (r_bytes == 0)
		{
			printf("End of file!\n");
			close(fd);
			free(big_buffer);
			free(buffer);
			return (0);
			//break;
		}
		// Is this null terminated str really neccesary, it is not enough with the callocated from the above?
		//fprintf(stderr, "I'm here after break\n");
		buffer[r_bytes] = '\0';
		big_buffer = append_buffer(big_buffer, buffer);
		//printf("big_buffer inside read loop is: %s\n", big_buffer);
		if (ft_strchr(big_buffer, '\n'))
		{
			//printf("nl found and loop broke in read_file()\n");
			break;
		}
	}
	//printf("Big Buffer outside loop is: %s\n", big_buffer);
	free(buffer);
	return(big_buffer);
	}



char * get_next_line(int fd) {

	static char	*big_buffer;
	char		*line;


	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 )
	{
		printf("Failed to open file or BUFFER_SIZE is too small\n");
		return(NULL);
	}
	if (!big_buffer)
	{
		big_buffer = ft_calloc(1, sizeof(char));
	}
	if (!ft_strchr(big_buffer, '\n'))
	{
		big_buffer = read_file(big_buffer, fd);
	}
	if (!big_buffer)
	{
		return(free(big_buffer), NULL);
	}
	line = extract_line(big_buffer);
	big_buffer = obtain_remaining(big_buffer, line);
 	return (line);
}



