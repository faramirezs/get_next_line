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

	nl_char = ft_calloc(1, sizeof(char));
	line = ft_calloc(1, sizeof(char));

	if (nl_char == NULL | line == NULL) {
		printf("Memory allocation failed at extract_line()\n");
		return(NULL);
	}
	else if (ft_strchr(big_buffer, '\n') != NULL)
	{
		nl_char = ft_strchr(big_buffer, '\n');
		line = ft_substr(big_buffer, 0, nl_char - big_buffer);
		printf("Line:%s\n", line);
		return(line);
	}
	else
	{
		free(line);
		free(nl_char);
		return(0);
	}

}

char *obtain_remaining (char *big_buffer, char *line)
{
	big_buffer = ft_substr(big_buffer, ft_strlen(line),ft_strlen(big_buffer));
	return (big_buffer);
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
			printf("End of file");
			close(fd);
			free(buffer);
			return(0);
		}
		buffer[r_bytes] = '\0';
		big_buffer = append_buffer(big_buffer, buffer);
		if (ft_strchr(big_buffer, '\n'))
			break;
		}
	printf("Buffer: %s\n", buffer);
	printf("Big Buffer: %s\n", big_buffer);

	free(buffer);
	return(big_buffer);
	}



char * get_next_line(int fd) {

	static char	*big_buffer;
	char		*line;


	if(fd < 0 || BUFFER_SIZE <= 0 )
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


/* char * _fill_line_buffer (int fd){

	ssize_t rd;
	size_t rbyte;
	size_t size_of_buffer;
	char * buffer;
	char * left_c;
	char * temp;

	rbyte = 5;
	rd = 1;
	buffer = malloc(rbyte);
	size_of_buffer = rbyte;
	left_c = malloc(1);
	*left_c = '\0';


	if (buffer == NULL | left_c == NULL) {
		printf("Memory allocation failed\n");
		return(NULL);
	}

	if (size_of_buffer < rbyte) {
		printf("Buffer overflow\n");
		return(NULL);
	}

	while (rd > 0){
		rd = read(fd, buffer, rbyte);
		if (rd == -1){
			printf("Read error");
			return(NULL);
		}
		else if (rd == 0)
		{
			printf("Final: %s\n", left_c);
			printf("End of file");
			close(fd);
			free(buffer);
			free(left_c);
			return(0);
		}
		else {
			buffer[rd] = '\0';
			// ft_strjoin allocates new memory and creates a new string
			temp = ft_strjoin(left_c, buffer);
			if (temp == NULL) {
				printf("ft_strjoin failed\n");
				return(NULL);
			}
			// Now we need to free the old memory that left_c is pointing to
			free(left_c);
			// And update left_c to point to the new memory
			left_c = temp;
			_set_line (left_c);
			if (left_c == NULL) {
				printf("Memory allocation failed\n");
				return(NULL);
			}
			size_of_buffer = size_of_buffer + rbyte;
			if (size_of_buffer < rbyte) {
				printf("Buffer overflow\n");
				return(NULL);
			}
		}
		printf("Buffer: %s\n", buffer);
		printf("Append: %s\n", left_c);
	}

	printf("Final: %s\n", left_c);
	close(fd);
	free(buffer);
	free(left_c);
	return(0);
} */



