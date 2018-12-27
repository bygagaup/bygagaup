/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:35:02 by tmann             #+#    #+#             */
/*   Updated: 2018/11/29 18:03:58 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*strone;
	unsigned char	*strtwo;
	size_t			i;

	strone = (unsigned char*)s1;
	strtwo = (unsigned char*)s2;
	i = 0;
	while (n > i)
	{
		if (strone[i] == strtwo[i])
		{
			i++;
		}
		else
			return (strone[i] - strtwo[i]);
	}
	return (0);
}
