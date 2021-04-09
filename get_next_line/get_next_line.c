/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 12:30:58 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/26 10:36:15 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

/*
** Saves given input to **line, but only until a possible '\n'. If a newline
** is encountered, the remainder after that is saved to the remainder list.
*/

static int	add_input(int fd, char **input, t_rlist **r_list, char **temp)
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
	if (remainder != NULL)
		return (update_remainder(fd, &remainder, r_list));
	else if (p != NULL)
		return (1);
	return (0);
}

/*
** Reads a line that ends either with newline '\n' or end-of-file EOF
** from the file descriptor fd and saves it in pointer to character **line.
** Possible return values are 1, 0, -1 according to whether a line has been
** read, reading has been completed (EOF reached) or whether an error occurred.
*/

int	get_next_line(const int fd, char **line)
{
	int				bytes_read;
	char			*temp;
	char			buf[BUFF_SIZE + 1];
	static t_rlist	*r_list;

	temp = NULL;
	if (fd < 0 || line == NULL)
		return (-1);
	if (r_list != NULL && read_remainder(fd, r_list, &temp, line) == 1)
		return (1);
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFF_SIZE);
		if (bytes_read == -1)
			return (-1);
		buf[bytes_read] = '\0';
		if (add_input(fd, &buf, &r_list, &temp) == 1)
			break ;
	}
	if (bytes_read == 0)
		delete_remainder(fd, &r_list);
	*line = temp;
	if (temp == NULL)
		return (0);
	return (1);
}
