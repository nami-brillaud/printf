# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfujisak <nfujisak@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/06 16:53:15 by nfujisak          #+#    #+#              #
#    Updated: 2024/05/10 16:30:56 by nfujisak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_helpers.c ft_printf.c ft_csp.c ft_base.c ft_diux.c

OBJS	= $(SRCS:.c=.o)

HEAD	= printf.h

NAME	= libftprintf.a

LIBFT	= libft/libft.a

AR		= ar rc

RM		= rm -f

LIB 	= ranlib

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

all		= ${NAME}

.c.o:
	${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	${MAKE} -C ./libft
	cp ${LIBFT} ${NAME}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

all: $(NAME)

clean:
	${MAKE} clean -C ./libft
	${RM} ${OBJS}

fclean:	clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re:		fclean all

.PHONY:	all bonus clean fclean re


