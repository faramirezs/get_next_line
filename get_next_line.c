#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"


/* char * _set_line (char *appended_string){
	// "appended_string" variable that will hold the appended string
	// Variable that will hold the new line character
	char * nl_char;
	// Variable that will hold the line
	char * line;

	nl_char = malloc(1);
	*nl_char = '\0';
	line = malloc(1);
	*line = '\0';

	if (nl_char == NULL | line == NULL) {
		printf("Memory allocation at _set_line failed\n");
		return(NULL);
	}
	else if (ft_strchr(appended_string, '\n') != NULL)
	{
		nl_char = ft_strchr(appended_string, '\n');
		line = ft_substr(appended_string, 0, nl_char - appended_string);
		printf("Line:%s\n", line);
		return(line);
	}
	else
		return(0);
} */

void    print_newline_helper(char *buffer)
{

    while (*buffer &&  *buffer != '\0')
    {
        if (*buffer == '\n')
        {
            *buffer= '\\';
        }
        printf("%c",*buffer);
        buffer++;
    }
}

char *read_file (int fd) {
	int r_bytes;
	char * buffer;
	static int count = 1;

	printf("ft_calloc#[%d]---", count++);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL) {
		printf("Memory allocation failed\n");
		return(NULL);
	}
	r_bytes = read(fd, buffer, BUFFER_SIZE);
	print_newline_helper(buffer);
	if (r_bytes <= 0)
		return(free(buffer), NULL);
	return(buffer);
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

char * get_next_line(int fd) {


	 char *gnl_buffer;


	if(fd == -1)
	{
		printf("Failed to open file\n");
		return(NULL);
	}
	else
	{
		printf("File opened with fd = %d\n", fd);
		gnl_buffer= read_file(fd);
 		return (gnl_buffer);
	}
}

