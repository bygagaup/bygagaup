/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:24:51 by tmann             #+#    #+#             */
/*   Updated: 2018/12/10 20:37:49 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*strl1;
	unsigned char	*strl2;
	size_t			i;

	if (dst == src)
		return (NULL);
	i = 0;
	strl2 = (unsigned char*)src;
	strl1 = (unsigned char*)dst;
	if (strl2 > strl1)
		while (i < len)
		{
			strl1[i] = strl2[i];
			i++;
		}
	else
		while (len--)
		{
			*(strl1 + len) = *(strl2 + len);
		}
	return (dst);
}
