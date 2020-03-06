/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 10:53:18 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/06 10:53:24 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*copy_from;
	unsigned char	*copy_to;
	size_t			index;

	if (!src && !dst)
		return (dst);
	copy_from = (unsigned char *)src;
	copy_to = (unsigned char *)dst;
	if (copy_from < copy_to)
	{
		while (len--)
			copy_to[len] = copy_from[len];
	}
	else
	{
		index = 0;
		while (index < len)
		{
			copy_to[index] = copy_from[index];
			index++;
		}
	}
	return (dst);
}
