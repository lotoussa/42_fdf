/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_create_sample.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:17:03 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 15:16:12 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

char		**ft_parse_sample(char **argv)
{
	t_parse		par;
	char		*tmp;
	int			fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (0);
	par.stock = ft_strnew(1);
	while (get_next_line(fd, &par.line))
	{
		tmp = par.stock;
		par.stock = ft_strjoin(par.stock, par.line);
		free(tmp);
		tmp = par.stock;
		par.stock = ft_strjoin(par.stock, "|");
		free(tmp);
		free(par.line);
	}
	par.sample = ft_strsplit(par.stock, '|');
	free(par.stock);
	close(fd);
	return (par.sample);
}

int			*ft_get_nbr(char *line, int *len)
{
	int			*tab;
	char		**split;
	int			i;

	*len = 0;
	split = ft_strsplit(line, ' ');
	while (split[*len])
		(*len)++;
	if (!(tab = (int*)malloc(sizeof(int) * (*len))))
		return (NULL);
	i = -1;
	while (split[++i])
		tab[i] = ft_atoi(split[i]);
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (tab);
}

t_point		*ft_fill_point(int *tab, int len, int x)
{
	int			i;
	t_point		*point;

	if (!(point = (t_point*)malloc(sizeof(t_point) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		point[i].y = x;
		point[i].x = i;
		point[i].z = tab[i];
		point[i].color = C_A;
		point[i].len = len;
		i++;
	}
	return (point);
}

t_point		**ft_convert_sample(char **sample)
{
	int			i;
	int			len;
	int			*tab;
	t_point		**point;

	i = 0;
	while (sample[i])
		i++;
	if (!(point = (t_point**)malloc(sizeof(t_point*) * (i) + 1)))
		return (NULL);
	point[i] = NULL;
	i = -1;
	while (sample[++i])
	{
		tab = ft_get_nbr(sample[i], &len);
		point[i] = ft_fill_point(tab, len, i);
		free(tab);
	}
	return (point);
}

t_point		**ft_create_sample(char **argv)
{
	int			i;
	char		**sample;
	t_point		**point;

	i = 0;
	sample = NULL;
	point = NULL;
	if (!(sample = ft_parse_sample(argv)))
		return (0);
	point = ft_convert_sample(sample);
	while (sample[i])
		free(sample[i++]);
	free(sample);
	return (ft_corner(point));
}
