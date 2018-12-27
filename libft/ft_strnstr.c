/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:02:42 by tmann             #+#    #+#             */
/*   Updated: 2018/12/04 15:25:15 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack,
		const char *needle, size_t len)
{
	size_t	i;
	size_t	lenstr;
	size_t	j;
	size_t	k;

	j = 0;
	i = 0;
	lenstr = ft_strlen(needle);
	while (haystack[i] && i < len)
	{
		k = i;
		while (haystack[k] == needle[j] && k < len)
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
