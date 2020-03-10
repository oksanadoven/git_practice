/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 14:03:23 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/03 11:43:20 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if ((new_str = ft_strnew(ft_strlen(s))))
	{
		while (s[i])
		{
			new_str[i] = f(s[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
