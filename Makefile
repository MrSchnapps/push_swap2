# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/10 15:20:38 by judecuyp          #+#    #+#              #
#    Updated: 2021/03/10 19:58:40 by judecuyp         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CH_NAME = checker

PS_NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I srcs/includes

SRCS_GNL = srcs/GNL/get_next_line.c \
			srcs/GNL/get_next_line_utils.c

SRCS_SH = srcs/shared/ft_free.c \
			srcs/shared/ft_lib.c \
			srcs/shared/ft_operation1.c \
			srcs/shared/ft_operation2.c \
			srcs/shared/ft_operation3.c \
			srcs/shared/ft_utils.c \
			srcs/shared/print.c \
			srcs/shared/parsing.c

SRCS_PUSH = srcs/push_swap/big_size.c \
			srcs/push_swap/big_size2.c \
			srcs/push_swap/ft_find.c \
			srcs/push_swap/main.c \
			srcs/push_swap/sort_three.c \
			srcs/push_swap/sort_stack.c

SRCS_CHECK = srcs/checker/main.c

OBJS_SH = $(SRCS_SH:.c=.o)

OBJS_PUSH =$(SRCS_PUSH:.c=.o)

OBJS_CHECK = $(SRCS_CHECK:.c=.o)

OBJS_GNL = $(SRCS_GNL:.c=.o)

RM = rm -rf

all : $(CH_NAME) $(PS_NAME)

$(CH_NAME) : $(OBJS_SH) $(OBJS_CHECK) $(OBJS_GNL)
	@$(CC) $(CFLAGS) -o $(CH_NAME) $(OBJS_SH) $(OBJS_CHECK) $(OBJS_GNL)

$(PS_NAME) : $(OBJS_SH) $(OBJS_PUSH)
	@$(CC) $(CFLAGS) -o $(PS_NAME) $(OBJS_SH) $(OBJS_PUSH)

clean:
	$(RM) $(OBJS_SH) $(OBJS_PUSH) $(OBJS_CHECK) $(OBJS_GNL)

	
fclean: clean
	$(RM) $(CH_NAME) $(PS_NAME)

re: fclean all

.PHONY: all clean fclean re

