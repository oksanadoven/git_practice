/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:49:51 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/06 10:49:56 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	index;

	if (!dst && !src)
		return (dst);
	index = 0;
	while (index < n)
	{
		((unsigned char*)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}
