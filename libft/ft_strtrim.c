/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osolodov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 10:10:55 by osolodov          #+#    #+#             */
/*   Updated: 2020/02/25 15:55:58 by osolodov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		start;
	int		finish;

	if (!s)
		return (NULL);
	start = 0;
	finish = ft_strlen(s) - 1;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	while (s[finish] == ' ' || s[finish] == '\t' || s[finish] == '\n')
		finish--;
	if (finish < start)
		trimmed = ft_strnew(0);
	else
		trimmed = ft_strsub(s, start, finish - start + 1);
	return (trimmed);
}
