# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fharifen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 13:13:28 by fharifen          #+#    #+#              #
#    Updated: 2024/03/27 13:38:11 by fharifen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS	=	ft_printf.c ft_printf_utils.c

INCLUDE	=	ft_printf.h
CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

%.o: %.c ${INCLUDE}
		${CC} ${CFLAGS} -c $< -o $@

OBJS	=	${SRCS:.c=.o}

${NAME}: ${OBJS} ${INCLUDE}
		ar rsc ${NAME} $^

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

.PHONY:	all clean re fclean
