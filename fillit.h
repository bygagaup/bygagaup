/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:23:21 by tmann             #+#    #+#             */
/*   Updated: 2018/12/28 16:32:24 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_tet
{
	char			**tet;
	char			alp;
	int				wi;
	int				he;
	int				x;
	int				y;
	int				stat;
	struct s_tet	*next;
	struct s_tet	*prev;
}					t_tet;

char				**ft_creatarr(char *namefile);
t_tet				*ft_valtet(char *namefile);
t_tet				*ft_newlsttet(char **arrtet, char alp);
void				ft_lstaddtet(t_tet **head, t_tet *list);
int					ft_countn(char *arrmap);
int					ft_counttet(t_tet *head);
char				**ft_map(int size);
int					ft_mapsize(int size);
char				**ft_alg(t_tet *head, int i, int k, int g);
void				ft_coordinate(t_tet **list);
void				ft_sizeteter(t_tet **list);
void				ft_addtetmap(char **map, t_tet *head, int i, int k);
int					ft_checkaddtetmap(char **map, t_tet *head, int i, int k);
char				**ft_remtet(t_tet *head, char **map);
void				ft_writemap(char **map);
int					ft_coordinateonmapx(char **map, t_tet *list, int g, int x);
int					ft_coordinateonmapy(char **map, t_tet *list, int g, int y);
void				ft_freemap(char **map);
void				ft_tmann(t_tet **list, t_tet *head, char ***map, int *g);
void				ft_fschille(t_tet **list, char ***map, int g);

#endif
