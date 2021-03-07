/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:30:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/02 21:04:15 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Deletes the node corresponding to fd from the remainder list. If it is
** the only node, it is deleted and remainder list is set to NULL.
*/

static void	ft_delete_remainder(int fd, t_rlist **r_list)
{
	t_rlist	*p;
	t_rlist *temp;

	p = *r_list;
	if (p != 0 && p->next == NULL && p->fd == fd)
	{
		free(*r_list);
		*r_list = NULL;
	}
	else if (p != 0 && p->fd == fd)
	{
		*r_list = p->next;
		free(p);
	}
	else if (p != 0 && p->next != 0)
	{
		while (p->next->fd != fd)
			p = p->next;
		if (p->next->fd == fd)
		{
			temp = p->next->next;
			free(p->next);
			p->next = temp;
		}
	}
}

/*
** Saves the given input to the remainder node corresponding to fd.
** If no node exists for the fd (or no list has yet been created),
** that is created and either added to end of existing list or saved
** as head of a new list.
*/

static int	ft_update_remainder(int fd, char **input, t_rlist **r_list)
{
	t_rlist *p;
	t_rlist *prev;

	p = *r_list;
	prev = NULL;
	while (p != NULL)
	{
		if (p->fd == fd)
		{
			p->remainder = *input;
			return (1);
		}
		prev = p;
		p = p->next;
	}
	if ((p = (t_rlist*)malloc(sizeof(t_rlist))) == NULL)
		return (-1);
	p->fd = fd;
	p->remainder = *input;
	p->next = NULL;
	if (prev != NULL)
		prev->next = p;
	else
		*r_list = p;
	return (1);
}

/*
** Saves given input to **line, but only until a possible '\n'. If a newline
** is encountered, the remainder after that is saved to the remainder list.
*/

static int	ft_add_input(int fd, char **input, t_rlist **r_list, char **temp)
{
	char	*p;
	char	*remainder;
	char	*new;

	remainder = NULL;
	p = ft_strchr(*input, '\n');
	if (p != NULL)
	{
		*p = '\0';
		if (*(p + 1) != '\0')
			remainder = ft_strdup(p + 1);
	}
	new = ft_strjoin(*temp, *input);
	if (*temp != NULL)
		free(*temp);
	*temp = new;
	free(*input);
	*input = NULL;
	if (remainder != NULL)
		return (ft_update_remainder(fd, &remainder, r_list));
	else if (p != NULL)
		return (1);
	return (0);
}

/*
** Checks whether something has been saved as a remainder from a
** previous call of get_next_line on this fd. If so, that is saved
** to **line.
*/

static int	ft_read_remainder(int fd, t_rlist *r_list, char **temp, char **line)
{
	t_rlist *p;
	int		ret;

	p = r_list;
	while (p != NULL)
	{
		if (p->fd == fd && p->remainder != NULL)
		{
			ret = ft_add_input(fd, &(p->remainder), &r_list, temp);
			if (ret == 1)
			{
				*line = *temp;
			}
			return (ret);
		}
		p = p->next;
	}
	return (0);
}

/*
** Reads a line that ends either with newline '\n' or end-of-file EOF
** from the file descriptor fd and saves it in pointer to character **line.
** Possible return values are 1, 0, -1 according to whether a line has been
** read, reading has been completed (EOF reached) or whether an error occurred.
*/

int			get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			*temp;
	char			*buf;
	static t_rlist	*r_list;

	temp = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	if (r_list != NULL && ft_read_remainder(fd, r_list, &temp, line) == 1)
		return (1);
	while ((buf = ft_strnew(BUFF_SIZE + 1)) != NULL &&
		(bytes_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		if (bytes_read == -1)
			return (-1);
		if (ft_add_input(fd, &buf, &r_list, &temp) == 1)
		{
			*line = temp;
			return (1);
		}
	}
	free(buf);
	ft_delete_remainder(fd, &r_list);
	*line = (temp == NULL) ? NULL : temp;
	return ((temp == NULL) ? 0 : 1);
}
