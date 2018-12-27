/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:16:11 by tmann             #+#    #+#             */
/*   Updated: 2018/12/05 16:55:22 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_size(int n)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		flag = 1;
		n = -n;
	}
	while (0 < n)
	{
		n = n / 10;
		i++;
	}
	return (i + flag);
}

static char			intinstr(int n)
{
	char	sim;

	sim = n + '0';
	return (sim);
}

static char			*numb(int n, size_t size)
{
	size_t		i;
	int			res2;
	char		*str;
	int			flag;

	flag = 0;
	str = ft_strnew(size);
	if (!str)
		return (NULL);
	i = size - 1;
	if (n < 0)
	{
		n = -n;
		flag = 1;
	}
	while (size > i)
	{
		res2 = n % 10;
		n = n / 10;
		str[i--] = intinstr(res2);
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}

char				*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(n);
	str = numb(n, size);
	return (str);
}
