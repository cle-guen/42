# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/31 15:38:51 by cle-guen          #+#    #+#              #
#    Updated: 2018/06/06 14:55:28 by cle-guen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS =  ft_printf.c\
		pf_putchar.c\
		pf_itoa_base.c\
		pf_memcpy.c\
		pf_get_value.c\
		pf_create_buffer.c\
		pf_put_buff.c\
		pf_put_wbuff.c\
		pf_write_buff.c\
		pf_dead_space.c\
		pf_strlen.c\
		pf_space.c\
		pf_minus.c\
		pf_l.c\
		pf_point.c\
		pf_star.c\
		pf_sharp.c\
		pf_zero.c\
		pf_width.c\
		pf_precision.c\
		pf_d.c\
		pf_gd.c\
		pf_u.c\
		pf_gu.c\
		pf_o.c\
		pf_go.c\
		pf_x.c\
		pf_gx.c\
		pf_p.c\
		pf_c.c\
		pf_s.c\
		pf_h.c\
		pf_j.c\
		pf_z.c\
		pf_plus.c\
		pf_gc.c\
		pf_gs.c

SRCS_PATH = $(addprefix srcs/, $(SRCS))

OBJ = $(SRCS_PATH:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -Ofast -c $< -I ./includes/ -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
