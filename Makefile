# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnesfane <mnesfane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/01 19:19:58 by mnesfane          #+#    #+#              #
#    Updated: 2022/04/05 05:37:28 by mnesfane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror
CC = gcc

CFILES = compair.c  utils.c push_swap.c moves.c moves2.c ps2.c sort.c bmoves.c bmoves2.c
BCFILES = checker.c  utils.c bmoves.c bmoves2.c swap_num.c get_next_line.c get_next_line_utils.c ps2.c compair.c sort.c #ps2.c

OCFILES = $(CFILES:.c=.o)
BOCFILES = $(BCFILES:.c=.o)

RM = rm -rf
NAME = push_swap
BNAME = checker 
INC = push_swap.h
BINC = checker.h

all : $(NAME)
bonus : $(BNAME)
$(NAME) : $(INC) $(OCFILES)
	$(CC) $(CFLAGS) $(OCFILES) -o push_swap
	
$(BNAME) : $(BINC) $(BOCFILES)
	$(CC) $(CFLAGS) $(BOCFILES) -o checker

clean :
	$(RM) $(OCFILES)
	$(RM) $(BOCFILES)
fclean : clean
	$(RM) $(NAME)
	$(RM) $(BNAME)

re : fclean all
reb : fclean bonus
