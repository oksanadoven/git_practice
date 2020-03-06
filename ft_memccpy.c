/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:43:24 by osolodov          #+#    #+#             */
/*   Updated: 2020/02/27 10:48:45 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	unsigned char		stop_char;
	size_t				i;

	source = (const unsigned char *)src;
	destination = (unsigned char *)dest;
	stop_char = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		destination[i] = source[i];
		if (destination[i] == stop_char)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
