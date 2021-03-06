/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:18:12 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/11 11:42:28 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	unsigned	len_s1;
	unsigned	len_s2;
	unsigned	i;

	len_s1 = (s1 ? ft_strlen(s1) : 0);
	len_s2 = (s2 ? ft_strlen(s2) : 0);
	if ((join = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1))))
	{
		i = 0;
		while (i < (len_s1 + len_s2))
			join[i++] = 0;
	}
	else
		join = NULL;
	if (!join || !s1 || !s2)
		return (NULL);
	join = ft_strcat(join, s1);
	join = ft_strcat(join, s2);
	return (join);
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
	char		*str;
	size_t		len;

	str = NULL;
	if ((*new_line_point = ft_strchr(leftover, '\n')))
	{
		str = ft_strsub(leftover, 0, *new_line_point - leftover);
		ft_strcpy(leftover, ++(*new_line_point));
	}
	else
	{
		len = ft_strlen(leftover);
		if (!(str = (char *)malloc(sizeof(char) * len + 1)))
			str = NULL;
		ft_strcat(str, leftover);
		if (leftover)
			while (len)
				leftover[len--] = 0;
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
	int		bytes_read;
	char	buffer[BUFFER_SIZE + 1];
	char	*new_line_point;
	char	*tmp;
	size_t	len;

	new_line_point = NULL;
	*line = find_nl(leftover, &new_line_point);
	while (!new_line_point && (bytes_read = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[bytes_read] = '\0';
		if ((new_line_point = ft_strchr(buffer, '\n')))
		{
			ft_strcpy(leftover, ++new_line_point);
			len = ft_strlen(--new_line_point) - 1;
			while (len--)
				new_line_point[len] = 0;
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buffer)) || bytes_read < 0)
			return (ERROR);
		free(tmp);
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

int		get_next_line(int fd, char **line)
{
	static char		*str[4096];
	int				result;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	if (!str[fd])
	{
		if (!(str[fd] = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (ERROR);
	}
	if ((result = get_line(fd, line, str[fd])) == READ_FINISHED)
		free(str[fd]);
	return (result);
}