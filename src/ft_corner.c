/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_corner.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/12 18:50:06 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 15:14:48 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

static int	ft_apply_max(t_point **point, int max)
{
	int		i;
	int		j;

	i = 0;
	while (point[i])
	{
		j = 0;
		while (j < point[i][j].len - 1)
		{
			point[i][j].color = (point[i][j].z < max ?
					point[i][j].color : C_B);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_color_max(t_point **point)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = point[0][0].z;
	while (point[i])
	{
		j = 0;
		while (j < point[i][j].len - 1)
		{
			max = (point[i][j].z > max ? point[i][j].z : max);
			j++;
		}
		i++;
	}
	ft_apply_max(point, max / 2);
	return (1);
}

t_point		**ft_corner(t_point **point)
{
	int		corner;
	int		i;
	int		j;

	corner = 0;
	while (point[corner])
		corner++;
	i = -1;
	while (point[++i])
	{
		j = 0;
		while (j < point[i][j].len)
			point[i][j++].corner = corner;
	}
	ft_color_max(point);
	return (point);
}
