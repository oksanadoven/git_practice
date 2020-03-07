/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:18:12 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/06 15:19:11 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Libraries for testing*/
#include <stdio.h>
#include <fcntl.h>
/*Delete*/

#include "get_next_line.h"

node	*create_el(int fd)
{
	node	*new;
	if (!(new = (node *)malloc(sizeof(node))))
		return (NULL);
	new->fd = fd;
	new->rest = ft_strnew(BUFF_SIZE);
	return (new);
}

char	*find_nl(char *str_remainder, char **line)
{
	char	*nl;

	nl = NULL;
	if (str_remainder)
	{
		if ((nl = ft_strchr(str_remainder, '\n')))
		{
			*nl = '\0';
			*line = ft_strdup(str_remainder);
			ft_strcpy(str_remainder, ++nl);
		}
		else
		{
			*line = ft_strdup(str_remainder);
			ft_strclr(str_remainder);
		}
	}
	else
		*line = ft_strnew(1);
	return (nl);
}

int		get_line(int fd, char **line, char *remain)
{

	int				bytes_read;
	char			buffer [BUFF_SIZE];
	char			*new_line;
	char			*tmp;

	new_line = find_nl(remain, line);
	while (!new_line && (bytes_read = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[bytes_read] = '\0';
		if ((new_line = ft_strchr(buffer, '\n')))
		{
			*new_line = '\0';
			new_line++;
			remain = ft_strdup(new_line);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buffer)) || bytes_read < 0)
			return (ERROR);
		free(tmp);
	}
	return ((bytes_read || ft_strlen(*line)) ? READ_NL : READ_FINISHED);
}

int		get_next_line(const int fd, char **line)
{
	static node		*head;
	node			*tmp;

	if (fd < 0 || !line)
		return (ERROR);
	if (!head)
		head = create_el(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = create_el(fd);
		tmp = tmp->next;
	}
	return (get_line(fd, line, tmp->rest));
}

/*TESTS*/
int main (void)
{
	int 	fd = open("read.txt", O_RDONLY);
	char	*line;
	int		result;

	while ((result = get_next_line(fd, &line)) > 0)
	{
		printf("FUNCTION WAS RUN WITH CODE >>%d<<\n", result);
		printf("%s\n\n", line);
	}
}
