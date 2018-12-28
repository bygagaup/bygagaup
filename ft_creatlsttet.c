/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatlsttet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 19:50:47 by tmann             #+#    #+#             */
/*   Updated: 2018/12/28 14:05:47 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tet			*ft_newlsttet(char **arrtet, char alp)
{
	t_tet *list;

	list = (t_tet*)malloc(sizeof(t_tet));
	if (!list)
		return (NULL);
	list->tet = arrtet;
	list->alp = alp;
	list->wi = 0;
	list->he = 0;
	list->x = 3;
	list->y = 3;
	list->stat = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void			ft_lstaddtet(t_tet **head, t_tet *list)
{
	t_tet	*tmp;

	tmp = *head;
	if (*head == NULL)
	{
		*head = list;
		(*head)->prev = NULL;
		(*head)->next = NULL;
	}
	else
	{
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = list;
		list->prev = tmp;
		list->next = NULL;
	}
}

void			ft_freemap(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}
