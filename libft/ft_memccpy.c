/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 15:55:25 by tmann             #+#    #+#             */
/*   Updated: 2018/12/10 14:04:23 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	unsigned const char	*copystr;

	i = 0;
	str = dst;
	copystr = src;
	while (i < n)
	{
		str[i] = copystr[i];
		if (copystr[i] == (unsigned char)c)
		{
			return ((unsigned char*)&str[i + 1]);
		}
		i++;
	}
	return (NULL);
}
