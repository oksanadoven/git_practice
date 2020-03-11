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
# include "libft/libft.h"

# define BUFF_SIZE 4096

# define ERROR -1
# define READ_FINISHED 0
# define READ_NL 1

int				get_next_line(const int fd, char **line);

typedef struct	s_node
{
	int				fd;
	char			*leftover;
	struct s_node	*next;
}				t_node;

#endif
