/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_key.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 21:03:05 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 16:17:24 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_key_second(int key, t_ptr *ptr)
{
	mlx_clear_window(ptr->mlx, ptr->win);
	if (key == CENTER)
	{
		ptr->op->pos_a = 80;
		ptr->op->pos_b = 150;
		ptr->op->size = (ptr->point[0][0].corner < 30 ? 22 : 1);
		ptr->op->angle = (ptr->point[0][0].corner < 30 ? 12 : 2);
		ptr->op->high = (ptr->point[0][0].corner < 30 ? 5 : 1);
	}
	ft_key(key, ptr);
	return (1);
}

int			ft_key(int key, t_ptr *ptr)
{
	if (key == ESC)
	{
		mlx_destroy_window(ptr->mlx, ptr->win);
		free(ptr);
		exit(EXIT_SUCCESS);
	}
	else if (key == HIGH_A)
		ptr->op->high = (ptr->op->high < 16 ?
				ptr->op->high * 1.2 : ptr->op->high);
	else if (key == HIGH_B)
		ptr->op->high = (ptr->op->high > 0 ? ptr->op->high * 0.8 : 0);
	else if (key == UP)
		ptr->op->pos_b -= 35;
	else if (key == DOWN)
		ptr->op->pos_b += 35;
	else if (key == LEFT)
		ptr->op->pos_a -= 35;
	else if (key == RIGHT)
		ptr->op->pos_a += 35;
	else if (key == PLUS)
		ptr->op->size += (ptr->op->size < 58 ? 1 : 0);
	else if (key == LESS)
		ptr->op->size -= (ptr->op->size > 0 ? 1 : 0);
	return (ft_handle(ptr, ptr->point));
}
