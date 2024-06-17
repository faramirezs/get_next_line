#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;
	int	i;
	int	j;

	i = 0;
	j = 0;
	tmp = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!tmp)
		return (NULL);
	while (s1[i])
	{
		tmp[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		tmp[i] = s2[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
	return (tmp);
}


char * _fill_line_buffer (int fd){

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


	if (buffer == NULL| left_c == NULL) {
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
			printf("End of file");
			return(0);
		}
		else {
			buffer[rd] = '\0';
			// ft_strjoin allocates new memory and creates a new string
			temp = ft_strjoin(buffer, left_c);
			if (temp == NULL) {
				printf("ft_strjoin failed\n");
				return(NULL);
			}
			// Now we need to free the old memory that left_c is pointing to
			free(left_c);
			// And update left_c to point to the new memory
			left_c = temp;
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
		free(left_c);
	}
	return(left_c);
	printf("Final: %s\n", left_c);
	close(fd);
	free(buffer);
	free(left_c);
}

char * get_next_line(int fd) {
	if(fd == -1){
		printf("Failed to open file\n");
		return(NULL);
	}
	else {
		 printf("File opened with fd = %d\n", fd);
		_fill_line_buffer(fd);
	}
}

int main() {

	int fd;
	fd = open("file.txt", O_RDONLY);
	get_next_line(fd);

}

