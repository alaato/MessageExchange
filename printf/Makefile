# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/09 20:49:40 by aatarban          #+#    #+#              #
#    Updated: 2024/02/05 17:22:41 by aatarban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	ft_printf.c ft_putaddress.c ft_putunsigned.c ft_puthex.c\
					ft_putchar.c ft_putnbr.c ft_puthex.c ft_strlen.c ft_putstr.c\
					
OBJS			= $(SRCS:.c=.o)


CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libftprintf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				@ar rcs $(NAME) $(OBJS)

clean:
				@$(RM) $(OBJS)

fclean:			clean
				@$(RM) $(NAME)

re:				@fclean $(NAME)


.PHONY:			all clean fclean re
