/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:35:16 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/03 15:14:14 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_abs(int n);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_count_words(char const *s, char c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_iswhitespace(char c);
char			*ft_itoa(int n);
void			*ft_memalloc(size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
int				ft_memcmp(void *restrict dest, const void *restrict src,
							size_t n);
void			*ft_memcpy(void *restrict dest, const void *restrict src,
							size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *str, int c, size_t n);
size_t			ft_num_len(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putchar(char c);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr_fd(int n, int fd);
void			ft_putnbr(int nb);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putstr(const char *str);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strcpy(char *dest, const char *src);
void			ft_strdel(char **as);
char			*ft_strdup(const char *src);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const*s2);
size_t			ft_strlcat(char *restrict dst, const char *restrict src,
							size_t dstsize);
size_t			ft_strlen(const char *str);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strncat(char *restrict dest, const char *restrict src,
							size_t nb);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dest, const char *src, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr (const char *big, const char *little, size_t len);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strpbrk(const char *s1, const char *s2);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *str, const char *to_find);
char			*ft_strsub(char const *s, unsigned intstart, size_t len);
char			*ft_strtrim(char const *s);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_strtrim(char const *s);

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

#endif
