/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 19:34:26 by tmann             #+#    #+#             */
/*   Updated: 2018/12/10 13:52:26 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstiter(t_list *lst, void (*f)(t_list*elem))
{
	t_list *save;

	if (!lst || !f)
		return ;
	while (lst->next != NULL)
	{
		save = lst->next;
		f(lst);
		lst = save;
	}
	f(lst);
}
