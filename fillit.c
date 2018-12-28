/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:33:34 by tmann             #+#    #+#             */
/*   Updated: 2018/12/28 14:05:09 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	t_tet	*head;
	char	**finmap;
	int		i;

	i = 0;
	if (argc == 2)
	{
		if ((head = ft_valtet(argv[1])) == NULL)
			write(1, "error\n", 6);
		finmap = ft_alg(head, 0, 0, 0);
		ft_writemap(finmap);
	}
	else
	{
		write(1, "usege: ./fillit source_file\n", 28);
	}
	return (0);
}
