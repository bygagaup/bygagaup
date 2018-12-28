/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foralg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:14:32 by fschille          #+#    #+#             */
/*   Updated: 2018/12/28 16:32:09 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_remtet(t_tet *head, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == head->alp)
				map[i][j] = '.';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

void		ft_writemap(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
}

int			ft_coordinateonmapx(char **map, t_tet *list, int g, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i] && map[i][j])
	{
		while (map[i][j] == list->alp)
		{
			if (x > j)
				x = j;
			j++;
		}
		if (j >= g - 1)
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	if (x != 27)
		return (x);
	else
		return (0);
}

int			ft_coordinateonmapy(char **map, t_tet *list, int g, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i] && map[i][j])
	{
		while (map[i][j] == list->alp)
		{
			if (y > i)
				y = i;
			j++;
		}
		if (j >= g - 1)
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	if (y != 27)
		return (y);
	else
		return (0);
}
