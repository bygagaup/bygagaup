/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freearr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:33:18 by tmann             #+#    #+#             */
/*   Updated: 2018/12/27 18:31:17 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_freearr(char **str, size_t j)
{
	size_t i;

	i = 0;
	if (str[j] == NULL)
	{
		while (j >= i)
		{
			ft_strdel(&str[i]);
			i++;
		}
		free(str);
		str = NULL;
	}
}
