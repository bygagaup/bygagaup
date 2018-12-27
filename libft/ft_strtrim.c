/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:21:29 by tmann             #+#    #+#             */
/*   Updated: 2018/12/02 15:22:37 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fun(char *str1, const char *str2, size_t start, size_t res)
{
	size_t i;

	i = 0;
	while (i < res)
	{
		str1[i] = str2[start + i];
		i++;
	}
	return (str1);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	res;

	start = 0;
	if (!s)
		return (NULL);
	end = ft_strlen(s);
	while (s[start] == '\n' || s[start] == '\t' || s[start] == ' ')
		start++;
	while (s[end - 1] == '\n' || s[end - 1] == '\t' || s[end - 1] == ' ')
		end--;
	if (start > end)
		res = start;
	else
		res = end - start;
	str = ft_strnew(res);
	if (s[start] == '\0')
		return (str);
	if (!str)
		return (NULL);
	fun(str, s, start, res);
	return (str);
}
