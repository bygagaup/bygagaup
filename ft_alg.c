/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 17:27:23 by tmann             #+#    #+#             */
/*   Updated: 2018/12/27 17:10:28 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			g_q;
int			g_l;

char		**ft_alg(t_tet *head, int i, int k, int g)
{
	char	**map;
	t_tet	*list;

	list = head;
	g = ft_mapsize(ft_counttet(head));
	map = ft_map(ft_mapsize(ft_counttet(head)));
	while (list != NULL)
	{
		if (list->wi - 1 + g_q >= g)
		{
			g_l++;
			g_q = 0;
		}
		if (list->he - 1 + g_l >= g)
		{
			g = g + 1;
			map = ft_map(g);
			list = head;
			g_q = 0;
			g_l = 0;
		}
		if (ft_checkaddtetmap(map, list, i, k))
		{
			ft_addtetmap(map, list, i, k);
			list = list->next;
			g_q = 0;
			g_l = 0;
			ft_writemap(map);
		}
		else
			g_q++;
	}
	return (map);
}

int			ft_checkaddtetmap(char **map, t_tet *h, int i, int k)
{
	int a;
	int b;

	a = h->x;
	b = h->y;
	while (k < h->he)
	{
		while (h->tet[h->y][h->x] != '\n' && i < h->wi)
		{
			if (map[g_l + k][g_q + i] != '.' && h->tet[h->y][h->x] == '#')
			{
				h->x = a;
				h->y = b;
				return (0);
			}
			i++;
			h->x = h->x + 1;
		}
		h->x = h->x - h->wi;
		h->y = h->y + 1;
		k++;
		i = 0;
	}
	h->y = h->y - h->he;
	return (1);
}

void		ft_addtetmap(char **map, t_tet *head, int i, int k)
{
	while (k < head->he)
	{
		while (head->tet[head->y][head->x] != '\n' && i < head->wi)
		{
			if (head->tet[head->y][head->x] == '#')
				map[g_l + k][g_q + i] = head->alp;
			i++;
			head->x = head->x + 1;
		}
		head->x = head->x - head->wi;
		head->y = head->y + 1;
		k++;
		i = 0;
	}
	head->y = head->y - head->he;
	head->stat = 1;
}
