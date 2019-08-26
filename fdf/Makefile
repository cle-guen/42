# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 15:38:51 by cle-guen          #+#    #+#              #
#    Updated: 2018/02/13 15:53:43 by cle-guen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = fdf

FRAMEWORK = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L ./libft -lft

SRC =	color.c\
		count.c\
		draw_line.c\
		get_model.c\
		help.c\
		key_funct.c\
		main.c\
		palette.c\
		trace_fdf.c\
		valid_file.c

SRCS = $(addprefix srcs/, $(SRC))

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	gcc $(FLAGS) $(FRAMEWORK) $(LIBFT) $^ -I includes/ -o $(NAME)

%.o: %.c includes/fdf.h
	gcc $(FLAGS) -c $< -o $@ -I includes/

clean:
	rm -f $(OBJ)
	make clean -C libft/
	make clean -C minilibx_macos/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
