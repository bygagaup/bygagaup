/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foralg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:14:32 by fschille          #+#    #+#             */
/*   Updated: 2018/12/27 17:12:45 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_statnull(t_tet *head)
{
	while (head != NULL)
	{
		head->stat = 0;
		head = head->next;
	}
}

void		ft_remtet(t_tet *head, char **map)
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
		i++;
	}
	head->stat = 0;
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
	write(1, "\n", 1); //удалить
}
