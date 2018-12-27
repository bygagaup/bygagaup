/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:16:34 by tmann             #+#    #+#             */
/*   Updated: 2018/12/09 17:39:44 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_countword(char *str, char c)
{
	int inword;
	int i;
	int word;

	word = 0;
	inword = 0;
	i = 0;
	while (str[i])
	{
		if (inword && str[i] == c)
		{
			inword = 0;
		}
		if (!inword && str[i] != c)
		{
			word++;
			inword = 1;
		}
		i++;
	}
	return (word);
}
