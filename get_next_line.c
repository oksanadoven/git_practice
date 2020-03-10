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

#include "get_next_line.h"

/* 
** Creates a new node of the linked list. The node will be created only in case
** a unique file descriptor is passed to the get_next_line() fn. The size of
** leftover str is reserved based on the BUFF_SIZE macro. It will be manipulated
** in the course of the program execution
*/

node	*create_el(int fd)
{
	node	*new;
	if (!(new = (node *)malloc(sizeof(node))))
		return (NULL);
	new->fd = fd;
	new->leftover = ft_strnew(BUFF_SIZE);
	new->next = NULL;
	return (new);
}

/* 
** If there's a leftover as a result of first time execution of the fn
** FIND_NL will 1) set new_line_point to the \n character in the leftover str
** 2) make a duplicate of the string from leftover till \n and put it in str
** 3) update leftover str by copying everything that remained after \n
** 
** If there's an empty leftover or there's no \n in leftover the fn
** will allocate a new str and append the contents of leftover to it. After
** that it will clear leftover (assuming that we reached EOF)
*/

char	*find_nl(char *leftover, char **new_line_point)
{
	char	*str;

	str = NULL;
	if ((*new_line_point = ft_strchr(leftover, '\n')))
	{
		str = ft_strsub(leftover, 0, *new_line_point - leftover);
		ft_strcpy(leftover, ++(*new_line_point));
	}
	else
	{
		str = ft_strnew(ft_strlen(leftover) + 1);
		ft_strcat(str, leftover);
		ft_strclr(leftover);
	}
	return (str);
}

/* 
** Fn GET_LINE executes the main functionality of the program: first it calls
** find_nl() fn which will pull the new line in case there was a leftover after 
** first execution of the program.
**
** If it is the first time execution and the result of the find_nl() call is 
** empty lines, the function starts reading the fd using read() fn call and 
** putting \0 either when it finished reading or if the BUFFER is full. Then it
** looks for a \n in the BUFFER and after it finds on, it copies everything
** after it into the leftover str and clears all the bytes before \n. After that
** it attaches str in BUFFER (ending at new_line_point) to the *line str and 
** returns the code of execution.
*/

int		get_line(int fd, char **line, char *leftover)
{
	int				bytes_read;
	char			buffer[BUFF_SIZE + 1];
	char			*new_line_point;
	char			*tmp;

	new_line_point = NULL;
	*line = find_nl(leftover, &new_line_point);
	while (!new_line_point && (bytes_read = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[bytes_read] = '\0';
		if ((new_line_point = ft_strchr(buffer, '\n')))
		{
			new_line_point++;
			ft_strcpy(leftover, new_line_point);
			ft_strclr(--new_line_point);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buffer)) || bytes_read < 0)
			return (ERROR);
		ft_strdel(&tmp);
	}
	return ((bytes_read || ft_strlen(*line)
			|| ft_strlen(leftover)) ? READ_NL : READ_FINISHED);
}

/* 
** GET_NEXT_LINE fn mainly deals with assigning multiple file descriptors
** to the corresponding node of the static linked list. If there's no list 
** it creates one, otherwise it traverses the nodes till fd given as a param
** matches the node->fd. If in the result of the traversal there was no node
** with a matching fd, it will create one and append it to the end of the list.
** After it made sure the node with the needed fd exists, it calls get_line() 
** fn to get the line. Being static, the nodes with corresponding fd contain
** the leftover strings as the result of each execution with a given fd.
*/

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
	return (get_line(fd, line, tmp->leftover));
}