# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

# define BUFF_SIZE 4096

# define ERROR -1
# define READ_FINISHED 0
# define READ_NL 1

int		get_next_line(const int fd,char **line);

typedef struct node
{
	int			fd;
	char		*leftover;
	struct node	*next;
}				node;

#endif
