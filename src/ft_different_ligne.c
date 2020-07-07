/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_different_ligne.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 19:58:40 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 16:10:29 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_while_ligne_a(t_ptr *ptr, t_ligne *l, int color)
{
	l->cumul = l->dx / 2;
	while (l->i <= l->dx)
	{
		l->x += l->xinc;
		l->cumul += l->dy;
		if (l->cumul >= l->dx)
		{
			l->cumul -= l->dx;
			l->y += l->yinc;
		}
		ft_setpx(ptr->data, l->x, l->y, color);
		l->i++;
	}
	return (1);
}

int			ft_while_ligne_b(t_ptr *ptr, t_ligne *l, int color)
{
	l->cumul = l->dy / 2;
	while (l->i <= l->dy)
	{
		l->y += l->yinc;
		l->cumul += l->dx;
		if (l->cumul >= l->dy)
		{
			l->cumul -= l->dy;
			l->x += l->xinc;
		}
		ft_setpx(ptr->data, l->x, l->y, color);
		l->i++;
	}
	return (1);
}

int			ft_ligne_a(t_ptr *ptr, t_point **point, int i, int j)
{
	t_ligne		*l;

	if (!(l = ft_init_ligne(ptr->op->size * point[i][j].x
					+ point[i][j].y * ptr->op->angle + ptr->op->pos_a,
					ptr->op->size * point[i][j].y
					- point[i][j].z * ptr->op->high + ptr->op->pos_b,
					ptr->op->size * point[i][j + 1].x
					+ point[i][j + 1].y * ptr->op->angle + ptr->op->pos_a,
					ptr->op->size * point[i][j + 1].y
					- point[i][j + 1].z * ptr->op->high + ptr->op->pos_b)))
		return (0);
	l->dx > l->dy ? ft_while_ligne_a(ptr, l, point[i][j].color)
		: ft_while_ligne_b(ptr, l, point[i][j].color);
	free(l);
	return (1);
}

int			ft_ligne_b(t_ptr *ptr, t_point **point, int i, int j)
{
	t_ligne		*l;

	if (!(l = ft_init_ligne(ptr->op->size * point[i][j].x
					+ point[i][j].y * ptr->op->angle + ptr->op->pos_a,
					ptr->op->size * point[i][j].y
					- point[i][j].z * ptr->op->high + ptr->op->pos_b,
					ptr->op->size * point[i + 1][j].x
					+ point[i + 1][j].y * ptr->op->angle + ptr->op->pos_a,
					ptr->op->size * point[i + 1][j].y
					- point[i + 1][j].z * ptr->op->high + ptr->op->pos_b)))
		return (0);
	if (point[i][j].color == C_B)
	{
		l->dx > l->dy ? ft_while_ligne_a(ptr, l, point[i][j].color)
			: ft_while_ligne_b(ptr, l, point[i][j].color);
	}
	else
	{
		if (l->dx <= l->dy && ptr->point[i][j].corner < 30)
			ft_while_ligne_b(ptr, l, point[i][j].color);
		else if (ptr->point[i][j].corner < 30)
			ft_while_ligne_a(ptr, l, point[i][j].color);
	}
	free(l);
	return (1);
}
