/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:32:59 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/03 13:44:59 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		i;

	len = ft_num_len(n);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	if (n == 0)
		str[i] = '0';
	if (n < 0)
		str[i] = '-';
	str[len--] = '\0';
	while (n)
	{
		str[len--] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	return (str);
}
