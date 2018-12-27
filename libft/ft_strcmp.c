/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 21:34:36 by tmann             #+#    #+#             */
/*   Updated: 2018/11/29 19:15:45 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*lenstr1;
	unsigned char	*lenstr2;

	lenstr1 = (unsigned char *)(s1);
	lenstr2 = (unsigned char *)(s2);
	while (*lenstr1 == *lenstr2 && *lenstr1)
	{
		lenstr1++;
		lenstr2++;
	}
	return ((unsigned int)*lenstr1 - (unsigned int)*lenstr2);
}
