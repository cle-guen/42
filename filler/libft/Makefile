# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 11:55:26 by cle-guen          #+#    #+#              #
#    Updated: 2018/10/17 17:32:21 by cle-guen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror -Ofast

NAME = libft.a

SRC = 		ft_atoi.c\
			ft_bzero.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memalloc.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memdel.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl.c\
			ft_putendl_fd.c\
			ft_putnbr.c\
			ft_putnbr_fd.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_strcat.c\
			ft_strchr.c\
			ft_strclr.c\
			ft_strcmp.c\
			ft_strcpy.c\
			ft_strdel.c\
			ft_strdup.c\
			ft_strequ.c\
			ft_striter.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlen.c\
			ft_strmap.c\
			ft_strmapi.c\
			ft_strncat.c\
			ft_strncmp.c\
			ft_strncpy.c\
			ft_strnequ.c\
			ft_strnew.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strsplit.c\
			ft_strstr.c\
			ft_strsub.c\
			ft_strtrim.c\
			ft_tolower.c\
			ft_toupper.c\
			ft_lstnew.c\
			ft_lstdelone.c\
			ft_lstdel.c\
			ft_lstadd.c\
			ft_lstiter.c\
			ft_lstmap.c\
			ft_lstaddend.c\
			ft_lstdeljoin.c\
			ft_lstprint.c\
			ft_putnbrl.c\
			ft_putaddress.c\
			ft_free_split.c\
			get_next_line.c\
			ft_printf.c\
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

SRCS = $(addprefix srcs/, $(SRC))

OBJ = $(SRCS:.c=.o)

INCLUDE =	libft.h\
			get_next_line.h\
			ft_printf.h

INCLUDES = $(addprefix includes/, $(INCLUDE))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c $(INCLUDES)
	gcc $(FLAGS) -c $< -o $@ -I includes/

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
