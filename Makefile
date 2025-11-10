# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: natakaha <natakaha@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 14:00:12 by natakaha          #+#    #+#              #
#    Updated: 2025/11/04 14:00:12 by natakaha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFLAGS = -Ilibft -Llibft -lft
SERVER = server
CLIANT = cliant
SERVER_SRCS = server.c
CLIANT_SRCS = cliant.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIANT_OBJS = $(CLIANT_SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(SERVER)

bonus: $(SERVER)

s: $(SERVER)

c: $(CLIANT)

$(SERVER) : $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIBFLAGS) -o $(SERVER)

$(CLIANT) : $(CLIANT_OBJS)
	$(CC) $(CFLAGS) $(CLIANT_OBJS) $(LIBFLAGS) -o $(CLIANT)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SERVER_OBJS) $(CLIANT_OBJS)

fclean: clean
	rm -f $(SERVER) $(CLIANT)

re: fclean all
