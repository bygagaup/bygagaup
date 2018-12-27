/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swappoint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:00:28 by tmann             #+#    #+#             */
/*   Updated: 2018/12/10 15:01:04 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swappoint(void *a, void *b, size_t len)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*q;
	unsigned char	tmp;

	i = 0;
	p = (unsigned char*)a;
	q = (unsigned char*)b;
	while (i != len)
	{
		tmp = p[i];
		p[i] = q[i];
		q[i] = tmp;
		i++;
	}
}
