# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aatarban <aatarban@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/05 15:36:12 by aatarban          #+#    #+#              #
#    Updated: 2024/02/05 17:22:15 by aatarban         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########COLORS#######

GREEN=\033[0;32m
RED=\033[0;31m
BLUE=\033[0;34m
END=\033[0m

NAMEC = client
NAMES = server

PRINTF = libftprintf.a

SRCC =	src/client.c
SRCS =	src/server.c

OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
INCLUDE = -I include
RM = rm -rf

all:	$(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
		@make -C printf
		@$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) printf/$(PRINTF) -o $(NAMEC)
		@echo "$(GREEN)server ready!"

$(NAMES) : $(OBJS)
		@make -C printf
		@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) printf/$(PRINTF) -o $(NAMES)
		@echo "$(GREEN)client ready!"

clean :
		@make clean -C printf
		@${RM} ${OBJC}
		@${RM} ${OBJS}
		@${RM} ${OBJBC}
		@${RM} ${OBJBS}
		@echo "$(GREEN)objects cleaned!"

fclean : clean
		@make fclean -C printf
		@${RM} $(NAMEC)
		@${RM} $(NAMES)
		@${RM} $(BONUS_NAMEC)
		@${RM} $(BONUS_NAMES)
		@${RM} $(PRINTF)
		@echo "$(GREEN)all cleaned cleaned!"

re : fclean all

.PHONY:		all bonus clean fclean re
