#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kradoste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 14:54:41 by kradoste          #+#    #+#              #
#    Updated: 2018/10/05 10:17:53 by kradoste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CFLAG = -Wall -Werror -Wextra
FILES = *.c
OBJ = *.o
BUP = *~

all : $(NAME)

$(NAME) :
		@gcc $(CFLAG) -c $(wildcard $(FILES))
		@ar rc $(NAME) $(OBJ)

.PHONY : clean fclean re

clean :
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(BUP)

fclean : clean
		@/bin/rm -f $(NAME)

re : fclean all
