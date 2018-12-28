/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valtet.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 14:11:43 by tmann             #+#    #+#             */
/*   Updated: 2018/12/28 14:01:31 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_checktet(char **arrtet, int i, int j, int k)
{
	while (arrtet[i] && arrtet[i][j])
	{
		while (arrtet[i][j] == '#')
		{
			if (j < 4 && arrtet[i][j + 1] == '#')
				k++;
			if (i > 0 && arrtet[i - 1][j] == '#')
				k++;
			if (j > 0 && arrtet[i][j - 1] == '#')
				k++;
			if (i < 3 && arrtet[i + 1][j] == '#')
				k++;
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
	if (k == 6 || k == 8)
		return (1);
	return (0);
}

char		**ft_onetotwo(char *arrmap)
{
	char	**arrtet;
	int		i;

	i = 0;
	arrtet = (char**)malloc(sizeof(char*) * 5);
	while (i <= 3)
	{
		arrtet[i] = ft_strsub(arrmap, (i * 4), 4);
		i++;
	}
	arrtet[i] = NULL;
	return (arrtet);
}

void		ft_sizeteter(t_tet **list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*list)->tet[i] && (*list)->tet[i][j])
	{
		while ((*list)->tet[i][j] == '#')
		{
			if ((*list)->he < i)
				(*list)->he = i;
			if ((*list)->wi < j)
				(*list)->wi = j;
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
	(*list)->he = (*list)->he + 1 - (*list)->y;
	(*list)->wi = (*list)->wi + 1 - (*list)->x;
}

t_tet		*ft_valtet(char *namefile)
{
	int		i;
	char	**arrtet;
	char	**arrtwomap;
	t_tet	*head;
	t_tet	*list;

	i = -1;
	head = NULL;
	if ((arrtwomap = ft_creatarr(namefile)) == NULL)
		return (NULL);
	while (arrtwomap[++i])
	{
		arrtet = ft_onetotwo(arrtwomap[i]);
		if (ft_checktet(arrtet, 0, 0, 0) == 0)
			return (NULL);
		list = ft_newlsttet(arrtet, 'A' + i);
		ft_coordinate(&list);
		ft_sizeteter(&list);
		ft_lstaddtet(&head, list);
	}
	return (head);
}
