/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 19:00:41 by tmann             #+#    #+#             */
/*   Updated: 2018/12/27 15:14:38 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_countn(char *arrmap)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (arrmap[i])
	{
		if (arrmap[i] == '\n')
			j++;
		i++;
	}
	return (j + 1);
}

int			ft_counttet(t_tet *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		i++;
		head = head->next;
	}
	return (i);
}

char		**ft_map(int size)
{
	char		**map;
	int			i;
	int			j;

	j = 0;
	i = 0;
	map = (char**)malloc(sizeof(char*) * size + 1);
	while (j < size)
	{
		map[j] = (char*)malloc(sizeof(char) * size + 1);
		while (i < size)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		i = 0;
		j++;
	}
	map[j] = NULL;
	return (map);
}

int			ft_mapsize(int size)
{
	int squaretet;
	int bestk;

	squaretet = size * 4;
	bestk = size * size;
	if (squaretet < bestk)
	{
		while (squaretet < bestk)
		{
			if (squaretet <= size * size)
				bestk = size * size;
			else
				break ;
			size--;
		}
	}
	else
	{
		while (squaretet > bestk)
		{
			bestk = size * size;
			size++;
		}
	}
	return (ft_sqrt(bestk));
}

void		ft_coordinate(t_tet **list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*list)->tet[i] && (*list)->tet[i][j])
	{
		while ((*list)->tet[i][j] == '#')
		{
			if ((*list)->y > i)
				(*list)->y = i;
			if ((*list)->x > j)
				(*list)->x = j;
			j++;
		}
		if (j >= 3)
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
}
