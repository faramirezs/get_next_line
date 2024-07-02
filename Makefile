# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alramire <alramire@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 11:33:51 by alramire          #+#    #+#              #
#    Updated: 2024/07/02 20:50:50 by alramire         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
CC = cc
FLAGS = -Wall -Wextra -Werror
# SRCS = *.c
SRCS = main.c get_next_line.c get_next_line_utils.c
# OBJS = *.o
OBJS = $(SRCS:.c=.o)

program: $(NAME)
	$(CC) -o program main.c $(NAME)
AR = ar rc
RM = rm -f
LIB	= ranlib

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) -c $(SRCS)
	$(AR) $(NAME) $(OBJS)
	$(LIB) $(NAME)

#$(NAME):
#	$(CC)  $(FLAGS) $(SRCS)
#	$(AR)  $(NAME) $(OBJS)
#	$(LIB) $(NAME)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
