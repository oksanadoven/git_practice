/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 15:08:08 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/03 12:03:42 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	else if (d > s)
	{
		d += n;
		s += n;
		while (n--)
		{
			d--;
			s--;
			*d = *s;
		}
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
