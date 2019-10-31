# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmorar <dmorar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/26 15:47:15 by dmorar            #+#    #+#              #
#    Updated: 2019/03/01 14:06:56 by dmorar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

OBJ = $(patsubst %.c, %.o, $(SRC))

SRC = ./src/main.c ./src/threads.c ./src/mandelbrot.c ./src/burningship.c ./src/julia.c ./src/colors.c ./src/spider.c

INC = fractol.h

LIB = ./libft/libft.a

FLAGS = -Wall -Werror -Wextra -Ofast

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc -g $(FLAGS) -o $(NAME) $^ -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB) -I $(INC) 

%.o:%.c
	gcc $(FLAGS) -c $^ -o $@ -I $(INC)

run: 
	gcc -g $(SRC) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit $(LIB) -I $(INC) -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean:	clean
	make fclean -C ./libft 
	/bin/rm -f $(NAME)

re: fclean all