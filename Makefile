# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zgodongw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/20 09:16:25 by zgodongw          #+#    #+#              #
#    Updated: 2017/10/24 17:29:57 by zgodongw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = system

SRC= main.cpp

all: $(NAME)

$(NAME):
	@g++ $(SRC) -std=c++14 -Wall -Werror -Wextra -o $(NAME) -O2

clean:
	@rm -f $(NAME)

re: clean all

1:
	@./$(NAME) ./tests/ex1.txt
2:
	@./$(NAME) ./tests/ex2.txt
3:
	@./$(NAME) ./tests/ex3.txt
4:
	@./$(NAME) ./tests/ex4.txt
5:
	@./$(NAME) ./tests/ex5.txt
6:
	@./$(NAME) ./tests/ex6.txt
7:
	@./$(NAME) ./tests/test.txt
8:
	@./$(NAME) ./tests/test1.txt
9:
	@./$(NAME) ./tests/test2.txt
sim:
	@./$(NAME) ./tests/simple.txt
b:
	@./$(NAME) ./tests/blocktest.txt



.PHONY: re clean all
