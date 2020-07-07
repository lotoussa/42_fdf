/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/07 18:14:10 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 15:13:20 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_handle(t_ptr *ptr, t_point **point)
{
	if (!(ft_print_fdf(ptr, point)))
		return (0);
	mlx_string_put(ptr->mlx, ptr->win, 10, 1, 0x00ffffff, "quit with ESC");
	mlx_string_put(ptr->mlx, ptr->win, 10, 21, 0x00ffffff, "move with arrows");
	mlx_string_put(ptr->mlx, ptr->win, 10, 42, 0x00ffffff, "zoom with + / -");
	mlx_string_put(ptr->mlx, ptr->win, 10, 85, 0x00ffffff,
			"reset with C");
	mlx_string_put(ptr->mlx, ptr->win, 10, 63, 0x00ffffff,
			"change the height with page up / down");
	mlx_key_hook(ptr->win, ft_key_second, ptr);
	return (1);
}

int			main(int argc, char **argv)
{
	t_ptr		*ptr;

	if (argc != 2)
	{
		ft_putendl_fd("usage: ./fdf map_file", 2);
		return (0);
	}
	if (!(ptr = (t_ptr*)malloc(sizeof(t_ptr))))
		return (0);
	if (!(ptr->point = ft_create_sample(argv)))
		return (0);
	if (!(ptr->op = ft_init_op(ptr)))
		return (0);
	ptr->mlx = mlx_init();
	ptr->win = mlx_new_window(ptr->mlx, LARG, HAUT, argv[1]);
	if (!(ft_handle(ptr, ptr->point)))
		return (0);
	mlx_loop(ptr->mlx);
	return (0);
}
