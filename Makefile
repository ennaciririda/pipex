# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 15:54:59 by rennacir          #+#    #+#              #
#    Updated: 2023/02/18 18:07:57 by rennacir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC  =  pipex.c  second_tools.c tools.c error_fun.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):  $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.c pipex.h
	$(CC) -c $(CFLAGS) $<

clean:
	rm -f $(OBJ) $(OBJBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus