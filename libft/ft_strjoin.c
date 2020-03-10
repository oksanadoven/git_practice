/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 17:48:58 by osolodov          #+#    #+#             */
/*   Updated: 2020/03/03 09:45:57 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*join;
	unsigned	len_s1;
	unsigned	len_s2;

	len_s1 = (s1 ? ft_strlen(s1) : 0);
	len_s2 = (s2 ? ft_strlen(s2) : 0);
	if (!(join = ft_strnew(len_s1 + len_s2)) || !s1 || !s2)
		return (NULL);
	join = ft_strcat(join, s1);
	join = ft_strcat(join, s2);
	return (join);
}
