#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 30
#endif

int		ft_strcmp(const char *str1, const char *str2);
size_t	ft_strlen(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif
