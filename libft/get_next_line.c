/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:53:39 by fschille          #+#    #+#             */
/*   Updated: 2018/12/17 13:33:36 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_checkn(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\0' && buf[i] != '\n')
		i++;
	return (i);
}

static t_list	*ft_checkfd(t_list **head, const int fd)
{
	t_list	*list;
	t_list	*tmp;

	tmp = *head;
	if ((*head) == NULL)
	{
		*head = ft_lstnew("", 1);
		(*head)->content_size = fd;
		return (*head);
	}
	while (tmp != NULL)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	list = ft_lstnew("", 1);
	list->content_size = fd;
	ft_lstadd(head, list);
	return (list);
}

static int		ft_outputline(char **line, t_list *list)
{
	char	*tmp;

	*line = ft_strsub(list->content, 0, ft_checkn(list->content));
	tmp = list->content;
	list->content = ft_strsub(list->content,
			(ft_checkn(list->content) + 1),
			(ft_strlen(list->content) -
			(ft_checkn(list->content))));
	free(tmp);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	long			byt;
	static t_list	*head;
	t_list			*list;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) > 0)
		return (-1);
	list = ft_checkfd(&head, fd);
	while ((byt = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[byt] = '\0';
		tmp = list->content;
		list->content = ft_strjoin(list->content, buf);
		free(tmp);
		if (ft_strchr(list->content, '\n'))
			return (ft_outputline(line, list));
	}
	if (byt < 0)
		return (-1);
	if (ft_strlen(list->content) && byt == 0)
		return (ft_outputline(line, list));
	return (0);
}
