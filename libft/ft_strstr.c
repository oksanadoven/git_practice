/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:40:13 by osolodov          #+#    #+#             */
/*   Updated: 2020/02/25 15:51:24 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int	j;
	int found_index;

	found_index = 0;
	j = 0;
	if (*to_find == '\0')
		return ((char *)str);
	while (str[found_index])
	{
		if (str[found_index] == *to_find)
		{
			while (str[found_index + j] == to_find[j] && to_find[j] != '\0')
				j++;
			if (to_find[j] == 0)
				return ((char *)str + found_index);
			else
				j = 0;
		}
		found_index++;
	}
	return (0);
}
