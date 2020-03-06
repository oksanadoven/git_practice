/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 13:21:43 by osolodov          #+#    #+#             */
/*   Updated: 2020/02/28 10:06:50 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void *restrict dest, const void *restrict src, size_t n)
{
	unsigned char		*str1;
	const unsigned char	*str2;

	str1 = (unsigned char *)dest;
	str2 = (const unsigned char *)src;
	while (n--)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		else
		{
			str1++;
			str2++;
		}
	}
	return (0);
}
