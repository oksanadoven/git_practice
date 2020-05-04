/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 12:59:33 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/10 15:12:40 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# define ERROR -1
# define READ_FINISHED 0
# define READ_NL 1

int				get_next_line(int fd, char **line);
char			*find_nl(char *leftover, char **new_line_point);
int				get_line(int fd, char **line, char *leftover);
char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strchr(const char *s, int c);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);

#endif
