/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_print_fdf.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 19:08:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 14:14:41 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_fill_image(t_ptr *ptr, t_point **point)
{
	int		i;
	int		j;

	i = 0;
	while (i < point[0][0].corner - 1)
	{
		j = 0;
		while (j < point[i][j].len)
		{
			if (!(ft_ligne_b(ptr, point, i, j)))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_print_fdf(t_ptr *ptr, t_point **point)
{
	int		n[3];
	int		i;
	int		j;

	if (!(ptr->img = mlx_new_image(ptr->mlx, LARG, HAUT)))
		return (0);
	if (!(ptr->data = (int*)mlx_get_data_addr(ptr->img, &n[0], &n[1], &n[2])))
		return (0);
	i = 0;
	while (point[i])
	{
		j = 0;
		while (j < point[i][j].len - 1)
		{
			if (!(ft_ligne_a(ptr, point, i, j)))
				return (0);
			j++;
		}
		i++;
	}
	if (!(ft_fill_image(ptr, point)))
		return (0);
	if (!(mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->img, 0, 0)))
		return (0);
	return (1);
}
