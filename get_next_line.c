#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char * get_next_line(int fd) {

	_fill_line_buffer(fd);

}

char * _fill_line_buffer (int fd){

	ssize_t rd;
	size_t rbyte;
	size_t size_of_buffer;
	char * buffer;
	char * left_c;

	rbyte = 5;
	rd = 1;
	buffer = malloc(rbyte);
	size_of_buffer = rbyte;


	if (buffer == NULL) {
		printf("Memory allocation failed\n");
		return(1);
	}

		if (size_of_buffer < rbyte) {
		printf("Buffer overflow\n");
		return(1);
	}

	while (rd > 0){
		rd = read(fd, buffer, rbyte);
		if (rd == -1){
			printf("Read error");
			return(-1);
		}
		else if (rd == 0)
		{
			printf("End of file");
			return(0);
		}
		else
			buffer[rd] = '\0';
		printf("Reading: %s\n", buffer);
	}
	close(fd);
	free(buffer);

}

int main() {
	int fd;
	ssize_t rd;
	size_t rbyte;
	size_t size_of_buffer;
	char * buffer;

	rbyte = 5;
	rd = 1;
	fd = open("file.txt", O_RDONLY);
	if(fd == -1){
		printf("Failed to open file\n");
		return(-1);
	}
	else
		 printf("File opened with fd = %d\n", fd);

	get_next_line(fd);

}

