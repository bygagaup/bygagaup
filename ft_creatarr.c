/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creatarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 18:03:03 by fschille          #+#    #+#             */
/*   Updated: 2018/12/21 19:29:25 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int				ft_checksim(char *line)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (line[j] != '.' && line[j] != '#')
			return (0);
		j++;
	}
	if (j == 4)
		return (1);
	return (0);
}

static int				ft_checkn(char *line)
{
	if (line[0] == '\0')
		return (1);
	return (0);
}

static int				ft_checklat(char *arrmap)
{
	int		i;
	int		j;
	int		numtet;

	i = 0;
	j = 0;
	numtet = 0;
	while (arrmap[i])
	{
		numtet++;
		while (arrmap[i] != '\n')
		{
			if (arrmap[i] == '#')
				j++;
			i++;
		}
		i++;
		if (j != 4)
			return (0);
		j = 0;
	}
	if (numtet <= 26)
		return (1);
	return (0);
}

static char				*ft_addarr(int fd, int i, char *line, char *arrmap)
{
	char *tmp;

	while (get_next_line(fd, &line) > 0)
	{
		if (--i > 0)
		{
			if (ft_checksim(line) == 0)
				return (NULL);
			tmp = arrmap;
			arrmap = ft_strjoin(arrmap, line);
			free(tmp);
			free(line);
		}
		else
		{
			if (ft_checkn(line) == 0)
				return (NULL);
			tmp = arrmap;
			arrmap = ft_strjoin(arrmap, "\n");
			free(tmp);
			free(line);
			i = 5;
		}
	}
	return (ft_strjoin(arrmap, "\n\0"));
}

char					**ft_creatarr(char *namefile)
{
	int		i;
	char	*line;
	char	*arrmap;
	char	**arrtwomap;

	i = 0;
	line = NULL;
	arrmap = ft_strdup("");
	if (!namefile)
		return (NULL);
	if ((arrmap = ft_addarr(open(namefile, O_RDONLY), 5, line, arrmap)) == NULL)
		return (NULL);
	arrtwomap = (char**)malloc(sizeof(char*) * ft_countn(arrmap));
	if (ft_checklat(arrmap) == 1)
	{
		while (arrmap[i * 16 + i])
		{
			arrtwomap[i] = ft_strsub(arrmap, i * 16 + i, 16);
			i++;
		}
		arrtwomap[i] = NULL;
		free(arrmap);
		return (arrtwomap);
	}
	return (NULL);
}
