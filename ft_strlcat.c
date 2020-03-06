/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:05:05 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/03 09:42:04 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	while (dst[i])
		i++;
	while (i < dstsize)
	{
		if (*src && (i < dstsize - 1))
			dst[i] = *src++;
		else
			dst[i] = '\0';
		i++;
	}
	return ((dstsize > dstlen ? dstlen : dstsize) + srclen);
}
