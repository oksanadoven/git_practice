/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:56:42 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/06 10:56:46 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string;
	size_t			index;

	string = (unsigned char *)s;
	index = 0;
	while (index < n)
	{
		if (string[index] == (unsigned char)c)
			return ((void *)(string + index));
		index++;
	}
	return (NULL);
}
