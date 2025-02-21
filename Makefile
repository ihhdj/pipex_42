# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iheb <iheb@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 10:57:00 by ihhadjal          #+#    #+#              #
#    Updated: 2025/02/21 08:40:31 by iheb             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = code/main.c code/utils.c code/utils2.c
OBJS = ${SRCS:.c=.o}
NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
RM = rm -rf
LIBFT = ./resources/libft


all : ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ./resources/libft/
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ./resources/libft/libft.a ${MLX_FLAGS}

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

clean:
	${MAKE} clean -C ./resources/libft/
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} ./resources/libft/libft.a

re: fclean all

.PHONY: all clean fclean re