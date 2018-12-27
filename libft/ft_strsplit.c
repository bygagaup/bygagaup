/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:25:36 by tmann             #+#    #+#             */
/*   Updated: 2018/12/21 16:52:10 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t		countsim(char *str, char c, size_t *i)
{
	int		counts;
	size_t	j;

	counts = 0;
	while (str[*i] == c)
		(*i)++;
	j = *i;
	while (str[j] != '\0' && str[j] != c)
	{
		counts++;
		j++;
	}
	return (counts);
}

static size_t		countwords(char *str, char c)
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

static char			*take(char *s, size_t *i, size_t countc)
{
	char		*str;
	size_t		k;

	str = ft_strnew(countc);
	if (!str)
		return (NULL);
	k = 0;
	while (k < countc)
	{
		str[k] = s[*i];
		(*i)++;
		k++;
	}
	return (str);
}

static char			**check(char **str, size_t j)
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
		return (NULL);
	}
	return (str);
}

char				**ft_strsplit(char const *s, char c)
{
	char		**str;
	size_t		i;
	size_t		sizew;
	size_t		countc;
	size_t		j;

	j = -1;
	i = 0;
	if (!s)
		return (NULL);
	sizew = countwords((char*)s, c);
	if (!(str = (char**)malloc(sizeof(char*) * sizew + 1)))
		return (NULL);
	while (sizew > ++j)
	{
		countc = countsim((char*)s, c, &i);
		str[j] = ft_strnew(countc);
		if (!str)
			return (NULL);
		if (check(str, j) == NULL)
			return (NULL);
		str[j] = take((char*)s, &i, countc);
	}
	str[j] = NULL;
	return (str);
}
