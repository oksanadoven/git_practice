# _*_ MakeFile _*_

NAME = libft.a
LIBNAMES = $(MANDATORY) $(BONUS)

CC = gcc -Wall -Wextra -Werror -I. -c

MANDATORY = ft_atoi ft_bzero ft_isalnum ft_isalpha ft_isascii ft_isdigit \
			ft_isprint ft_itoa ft_lstadd ft_lstdel ft_lstdelone ft_lstiter \
			ft_lstmap ft_lstnew ft_memalloc ft_memccpy ft_memchr ft_memcmp \
			ft_memcpy ft_memdel ft_memmove ft_memset ft_putchar ft_putchar_fd \
			ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr \
			ft_putstr_fd ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy \
			ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin \
			ft_strlcat ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp \
			ft_strncpy ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_strsplit \
			ft_strstr ft_strsub ft_strtrim ft_tolower ft_toupper
BONUS = 	ft_count_words ft_num_len ft_abs ft_iswhitespace

SRC = $(addsuffix .c,$(LIBNAMES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
