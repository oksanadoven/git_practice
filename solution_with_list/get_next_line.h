/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:59:33 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/10 15:12:40 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR -1
# define READ_FINISHED 0
# define READ_NL 1

typedef struct	s_node
{
	int				fd;
	char			*leftover;
	struct s_node	*next;
}				t_node;

int				get_next_line(int fd, char **line);
t_node			*create_node(int fd);
void			delete_node(t_node **head, t_node *delete);
char			*find_nl(char *leftover, char **new_line_point);
int				get_line(int fd, char **line, char *leftover);

char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_1cpy_2cat(char *dest, const char *src, int code);

#endif
