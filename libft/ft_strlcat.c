/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 14:38:47 by tmann             #+#    #+#             */
/*   Updated: 2018/12/04 22:16:46 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t j;
	size_t sizedst;
	size_t sizesrc;

	j = 0;
	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	if (size > sizedst)
	{
		size = size - sizedst - 1;
		while (src[j] != '\0' && size > j)
		{
			dst[sizedst + j] = src[j];
			j++;
		}
		dst[sizedst + j] = '\0';
		return (sizedst + sizesrc);
	}
	return (sizesrc + size);
}
