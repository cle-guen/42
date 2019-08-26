# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 15:38:51 by cle-guen          #+#    #+#              #
#    Updated: 2018/03/22 15:58:58 by cle-guen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = fractol

FRAMEWORK = -L ./minilibx_macos -lmlx -framework OpenGL -framework AppKit

LIBFT = -L ./libft -lft

SRC =	main.c\
		close_program.c\
		window.c\
		ft_hook.c\
		set_fract.c\
		input_funct.c\
		mouse_funct.c\
		state_key.c\
		help.c\
		info.c\
		tab_color.c\
		init_img.c\
		ft_put_pixels.c\
		parse.c\
		zoom.c\
		multi_thread.c\
		calc_fract.c

SRCS = $(addprefix srcs/, $(SRC))

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos/
	gcc $(FLAGS) $(FRAMEWORK) $(LIBFT) $^ -I includes/ -o $(NAME)

%.o: %.c includes/fractol.h
	gcc $(FLAGS) -c $< -o $@ -I includes/

clean:
	rm -f $(OBJ)
	make clean -C libft/
	make clean -C minilibx_macos/

fclean: clean
	rm -f $(NAME)
	make fclean -C libft/

re: fclean all
