# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 15:38:51 by cle-guen          #+#    #+#              #
#    Updated: 2018/11/05 15:00:38 by cle-guen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -Ofast

NAME = cle-guen.filler

LIBFT = -L ./libft -lft

SRC =	main.c\
		parse.c\
		calcul_heat_map.c\
		algo.c\
		free_game.c

SRCS = $(addprefix srcs/, $(SRC))

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	gcc $(FLAGS) $(LIBFT) $^ -I includes/ -o $(NAME)

%.o: %.c includes/filler.h
	gcc $(FLAGS) -c $< -o $@ -I includes/

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
