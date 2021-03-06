/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:18:12 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/11 11:42:28 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*find_nl(char *remainder, char **new_line_point)
{
	char		*str;
	size_t		len;

	str = NULL;
	if (remainder)
	{
		if ((str = ft_strchr(remainder, '\n')))
		{
			*str = '\0';
			*new_line_point = ft_strdup(remainder);
			ft_strcpy(remainder, ++str);
		}
		else
		{
			*new_line_point = ft_strdup(remainder);
			len = ft_strlen(remainder);
			if (remainder)
				while (len)
					remainder[len--] = 0;
		}
	}
	else
		*new_line_point = (char *)malloc(sizeof(char) * 2);
	return (str);
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
	static char	*remainder;
	char 		buff[BUFFER_SIZE + 1];
	char		*new_line_point;
	char		*tmp;
	int			bytes_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	new_line_point = find_nl(remainder, line);
	while (!new_line_point && (bytes_read = read(fd, buff, BUFFER_SIZE)))
	{
		buff[bytes_read] = '\0';
		if ((new_line_point = ft_strchr(buff, '\n')))
		{
			*new_line_point = '\0';
			new_line_point++;
			remainder = ft_strdup(new_line_point);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(tmp, buff)) || bytes_read < 0)
			return (ERROR);
		free(tmp);
	}
	return ((bytes_read || ft_strlen(*line)
			|| ft_strlen(remainder)) ? READ_NL : READ_FINISHED);
}