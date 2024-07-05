/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alramire <alramire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:45:40 by alramire          #+#    #+#             */
/*   Updated: 2024/07/05 11:45:49 by alramire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1
#endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

size_t	ft_strlen(char const *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd);

#endif
