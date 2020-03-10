/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:55:59 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/06 10:56:01 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst, const void *restrict src,
		int c, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			index;

	source = (unsigned char *)src;
	destination = (unsigned char *)dst;
	index = 0;
	while (index < n)
	{
		destination[index] = source[index];
		if (source[index] == (unsigned char)c)
			return ((void *)(destination + index + 1));
		index++;
	}
	return (NULL);
}
