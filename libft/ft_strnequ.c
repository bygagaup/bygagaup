/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 16:01:35 by tmann             #+#    #+#             */
/*   Updated: 2018/12/01 16:55:50 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	if (n == 0)
		return (1);
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > i)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (1);
		i++;
	}
	if (n == i)
		return (1);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}
