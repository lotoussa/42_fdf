/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 19:24:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 15:39:12 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

t_op		*ft_init_op(t_ptr *ptr)
{
	t_op	*op;

	if (!(op = (t_op*)malloc(sizeof(t_op))))
		return (NULL);
	op->size = (ptr->point[0][0].corner < 30 ? 22 : 1);
	op->angle = (ptr->point[0][0].corner < 30 ? 12 : 2);
	op->high = (ptr->point[0][0].corner < 30 ? 5 : 1);
	op->pos_a = LARG / 3.3;
	op->pos_b = HAUT / 2.8;
	return (op);
}

t_ligne		*ft_init_ligne(int xi, int yi, int xf, int yf)
{
	t_ligne		*l;

	if (!(l = (t_ligne*)malloc(sizeof(t_ligne))))
		return (NULL);
	l->x = xi;
	l->y = yi;
	l->dx = xf - xi;
	l->dy = yf - yi;
	l->xinc = (l->dx > 0) ? 1 : -1;
	l->yinc = (l->dy > 0) ? 1 : -1;
	l->dx = l->dx > 0 ? l->dx : -l->dx;
	l->dy = l->dy > 0 ? l->dy : -l->dy;
	l->i = 1;
	return (l);
}
