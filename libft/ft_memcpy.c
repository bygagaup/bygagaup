/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 21:46:47 by tmann             #+#    #+#             */
/*   Updated: 2018/12/27 18:32:57 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*str;
	unsigned const char	*copystr;
	size_t				i;

	if (dst == src)
		return (NULL);
	i = 0;
	copystr = src;
	str = dst;
	while (n > i)
	{
		str[i] = copystr[i];
		i++;
	}
	return (dst);
}
