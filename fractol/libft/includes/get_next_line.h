/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 14:09:25 by cle-guen          #+#    #+#             */
/*   Updated: 2018/01/11 16:47:16 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 20

# include "libft.h"
# include <fcntl.h>

typedef struct		s_line
{
	char			*content;
	struct s_line	*next;
	int				fd;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
