# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 22:11:39 by athonda           #+#    #+#              #
#    Updated: 2024/06/06 00:11:25 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_printfunction.c

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

CFLAGS	=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $@ $?

%.o: %.c ft_printf.h
		cc $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re