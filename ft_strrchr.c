/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:12:40 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/03 16:17:11 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_oc;

	last_oc = NULL;
	while (*s)
	{
		if (*s == c)
			last_oc = (char *)s;
		s++;
	}
	if (*s == c)
		last_oc = (char *)s;
	return (last_oc);
}
