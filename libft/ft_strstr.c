/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:51:17 by tmann             #+#    #+#             */
/*   Updated: 2018/11/29 16:22:17 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	lenstr;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	lenstr = ft_strlen(needle);
	while (haystack[i])
	{
		k = i;
		while (haystack[k] == needle[j])
		{
			j++;
			k++;
			if (needle[j] == '\0')
				return ((char*)&haystack[i]);
		}
		k = 0;
		j = 0;
		i++;
	}
	if (needle[j] == '\0')
		return ((char*)haystack);
	return (NULL);
}
