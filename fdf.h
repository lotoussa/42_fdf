/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fdf.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lotoussa <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/01 05:19:41 by lotoussa     #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 15:13:37 by lotoussa    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <libft.h>
# include <math.h>

# define LARG 2300
# define HAUT 1300
# define ESC 53
# define UP 126
# define RIGHT 124
# define DOWN 125
# define LEFT 123
# define PLUS 69
# define LESS 78
# define HIGH_A 116
# define HIGH_B 121
# define CENTER 8
# define C_A 0x005472AE
# define C_B 0x00FFA500

typedef struct		s_ligne
{
	int				dx;
	int				dy;
	int				k;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
	int				i;
}					t_ligne;

typedef struct		s_op
{
	double			size;
	double			angle;
	double			high;
	double			pos_a;
	double			pos_b;
}					t_op;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				len;
	int				corner;
}					t_point;

typedef struct		s_ptr
{
	t_point			**point;
	t_op			*op;
	int				*data;
	void			*mlx;
	void			*win;
	void			*img;
}					t_ptr;

typedef struct		s_parse
{
	char			**sample;
	char			*line;
	char			*stock;
}					t_parse;

void				ft_setpx(int *img, int x, int y, int color);
t_point				**ft_create_sample(char **argv);
int					ft_print_fdf(t_ptr *ptr, t_point **point);
t_op				*ft_init_op(t_ptr *ptr);
t_ligne				*ft_init_ligne(int xi, int yi, int xf, int yf);
int					ft_ligne_a(t_ptr *ptr, t_point **point, int i, int j);
int					ft_ligne_b(t_ptr *ptr, t_point **point, int i, int j);
int					ft_while_ligne_a(t_ptr *ptr, t_ligne *l, int color);
int					ft_while_ligne_b(t_ptr *ptr, t_ligne *l, int color);
int					ft_key(int key, t_ptr *ptr);
int					ft_key_second(int key, t_ptr *ptr);
int					ft_handle(t_ptr *ptr, t_point **point);
t_point				**ft_corner(t_point **point);

#endif
