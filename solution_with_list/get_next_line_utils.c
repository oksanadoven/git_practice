/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:18:12 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/11 11:42:28 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s++)
			return (0);
	}
	return ((char *)s);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if ((substr = (char *)malloc(sizeof(char) * len + 1)))
	{
		i = -1;
		while (++i < len)
			substr[i] = 0;
	}
	else
		return (NULL);
	i = 0;
	while (i < len)
		substr[i++] = s[start++];
	return (substr);
}

char	*ft_1cpy_2cat(char *dest, const char *src, int code)
{
	if (code == 1)
	{
		unsigned	i;

		i = 0;
		while (src[i] != 0)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	else
	{
			char *d;

		d = dest;
		while (*dest)
			dest++;
		while ((*dest++ = *src++))
			;
		return (d);
	}
}

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
	join = ft_1cpy_2cat(join, s1, 2);
	join = ft_1cpy_2cat(join, s2, 2);
	return (join);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}