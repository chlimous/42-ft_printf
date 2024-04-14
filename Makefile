# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chlimous <chlimous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 00:05:37 by chlimous          #+#    #+#              #
#    Updated: 2024/04/13 19:12:38 by chlimous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS += $(addprefix src/, ft_printf.c ft_printf2.c utils.c utils2.c)
SRCS += $(addprefix src/buffer/, add_back.c add_node.c buffer_to_string.c clear_buffer.c flush.c new_node.c)
SRCS += $(addprefix src/parser/, parse_elem.c parse_flags.c set_flags.c parse_width.c parse_precision.c parse_length.c parse_formatid.c utils.c)
SRCS += $(addprefix src/exec/, formatid_c.c formatid_s.c formatid_p.c formatid_d.c formatid_u.c formatid_x.c formatid_percent.c formatid_n.c formatid_o.c formatid_k.c utils.c handle_unsigned.c handle_unsigned2.c handle_signed.c handle_signed2.c)

OBJS = $(SRCS:.c=.o)

INCLUDE = include

CC = cc

CFLAGS = -Wall -Wextra -Werror

C_GREEN=\e[32m
C_END=\e[0m

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus: all

deb: $(NAME)
	@$(CC) main.c -I include -I libft/include -L. -lftprintf
	@echo  "\n"
	@./a.out
	
debv: $(NAME)
	@$(CC) main.c -I include -I libft/include -L. -lftprintf
	@echo  "\n"
	@valgrind --leak-check=full ./a.out

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
