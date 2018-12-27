/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:53:05 by tmann             #+#    #+#             */
/*   Updated: 2018/11/29 19:02:54 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*p;

	p = s;
	while (*p != '\0')
	{
		p++;
	}
	while (p >= s)
	{
		if (*p == (unsigned char)c)
			return ((char*)p);
		p--;
	}
	return (NULL);
}
