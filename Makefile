# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 21:44:04 by chlimous          #+#    #+#              #
#    Updated: 2023/11/24 21:44:32 by chlimous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = $(addprefix src/, ft_printf.c formatid_char.c formatid_string.c formatid_ptr.c formatid_intbase.c \
       formatid_uintbase.c formatid_percent.c formatid_unknown.c utils.c)

OBJS = ${SRCS:.c=.o}

INCLUDE = include

CC = cc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}

all : ${NAME}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re
