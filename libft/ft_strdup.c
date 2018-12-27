/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:25:45 by tmann             #+#    #+#             */
/*   Updated: 2018/12/04 20:34:40 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*strmall;
	unsigned long	size;
	unsigned long	i;

	size = 0;
	i = 0;
	while (s1[size])
	{
		size++;
	}
	strmall = (char*)malloc((size + 1) * sizeof(char));
	if (!strmall)
		return (NULL);
	while (s1[i])
	{
		strmall[i] = s1[i];
		i++;
	}
	strmall[i] = '\0';
	return (strmall);
}
