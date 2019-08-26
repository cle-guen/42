/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-guen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 12:50:15 by cle-guen          #+#    #+#             */
/*   Updated: 2018/02/09 14:14:55 by cle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_strn(char *str)
{
	int		i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

static int		ft_add_to_rest(char *buff, t_line **lst)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	len = ((*lst)->content ? ft_strlen((*lst)->content) : 0);
	if (!(tmp = (char *)malloc(sizeof(char) * len + ft_strlen(buff) + 1)))
		return (0);
	i = 0;
	while ((*lst)->content && (*lst)->content[i])
	{
		tmp[i] = (*lst)->content[i];
		i++;
	}
	j = 0;
	while (buff[j])
		tmp[i++] = buff[j++];
	tmp[i] = '\0';
	free((*lst)->content);
	(*lst)->content = tmp;
	return (1);
}

static void		ft_add_to_line(char **line, t_line **lst)
{
	char	*tmp;
	int		i;

	i = 0;
	while ((*lst)->content[i] && (*lst)->content[i] != '\n')
		i++;
	*line = ft_strsub((*lst)->content, 0, i);
	i += ((*lst)->content[i] && (*lst)->content[i] == '\n' ? 1 : 0);
	if ((*lst)->content[i])
		tmp = ft_strsub((*lst)->content, i, ft_strlen((*lst)->content));
	else
		tmp = ft_strdup("\0");
	free((*lst)->content);
	(*lst)->content = tmp;
}

static int		ft_change_fd(t_line **lst, int fd)
{
	t_line	*prev;

	prev = NULL;
	while (*lst && (*lst)->fd != fd)
	{
		prev = *lst;
		*lst = (*lst)->next;
	}
	if (!(*lst))
	{
		if (!(*lst = (t_line *)malloc(sizeof(t_line))))
			return (0);
		(*lst)->content = ft_strdup("\0");
		(*lst)->next = NULL;
		(*lst)->fd = fd;
		if (prev)
			prev->next = *lst;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_line	*lst = NULL;
	char			buff[BUFF_SIZE + 1];
	int				len;
	t_line			*first;

	first = lst;
	len = 0;
	if (fd < 0 || line == NULL || read(fd, buff, 0) < 0)
		return (-1);
	ft_change_fd(&lst, fd);
	while (ft_strn(lst->content) == 0 && (len = read(fd, buff, BUFF_SIZE)))
	{
		buff[len] = '\0';
		ft_add_to_rest(buff, &lst);
	}
	if (lst->content[0])
	{
		ft_add_to_line(&(*line), &lst);
		lst = first ? first : lst;
		return (1);
	}
	lst = first ? first : lst;
	return (len ? 1 : 0);
}
