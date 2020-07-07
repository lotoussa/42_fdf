/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/21 15:23:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/21 15:36:43 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		ft_recupline(char **save, char *next, char **line)
{
	char	*tmp;

	if (!(*line = ft_strsub(*save, 0, next - *save)))
		return (-1);
	tmp = *save;
	if (!(*save = ft_strdup(next + 1)))
		return (-1);
	free(tmp);
	return (1);
}

static int		ft_multi_fd(int fd, char **line, char **save)
{
	t_content		a;
	char			*tmp;

	if (fd < 0 || !line)
		return (-1);
	a.i = 0;
	if ((a.next = ft_strchr(*save, '\n')))
		return (ft_recupline(save, a.next, line));
	while ((a.ret = read(fd, a.buf, BUFF_SIZE)) > 0)
	{
		a.buf[a.ret] = '\0';
		tmp = *save;
		if (!(*save = ft_strjoin(*save, a.buf)))
			return (-1);
		free(tmp);
		if (ft_strchr(*save, '\n'))
			return (ft_multi_fd(fd, line, save));
		*line = *save;
		a.i = 1;
	}
	save = NULL;
	if (a.ret == -1)
		return (-1);
	return (a.i ? 1 : 0);
}

int				get_next_line(const int fd, char **line)
{
	t_fd			*current;
	static t_fd		*list;

	if (list)
	{
		current = list;
		while (current && current->fd != fd)
			current = current->next;
		if (current)
			return (ft_multi_fd(fd, line, &current->save));
	}
	if (!(current = (t_fd *)malloc(sizeof(t_fd))))
		return (-1);
	current->fd = fd;
	current->next = (list) ? list : NULL;
	list = current;
	if (!(current->save = (char *)malloc(sizeof(char))))
		return (-1);
	return (ft_multi_fd(fd, line, &current->save));
}
