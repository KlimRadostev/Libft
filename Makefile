#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kradoste <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/16 14:54:41 by kradoste          #+#    #+#              #
#    Updated: 2019/10/31 01:52:51 by kradoste         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CFLAG = -Wall -Werror -Wextra
FILES = */*.c
OBJ = *.o
BUP = *~

OBJ_DIR = objects

all : $(NAME)

$(NAME) :
		@gcc $(CFLAG) -c $(wildcard $(FILES))
		@ar rc $(NAME) $(OBJ)
		@mkdir $(OBJ_DIR)
		@mv $(OBJ) $(OBJ_DIR)
		@echo "\033[32mCOMPILED LIBFT\033[0m"

.PHONY : clean fclean re

clean :
		@/bin/rm -rf $(OBJ_DIR)
		@/bin/rm -f $(OBJ)
		@/bin/rm -f $(BUP)

fclean : clean
		@/bin/rm -f $(NAME)

re : fclean all
