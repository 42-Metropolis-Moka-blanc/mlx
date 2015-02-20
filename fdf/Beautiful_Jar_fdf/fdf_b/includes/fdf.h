/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:06:01 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/02/20 18:04:54 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <X.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define HEIGHT 2000
# define WIDTH 2000
# define TZ e->rz
# define TX e->rx
# define X1 e->inc->x1
# define X2 e->inc->x2
# define Y1 e->inc->y1
# define Y2 e->inc->y2
# define Z1 e->inc->z1
# define Z2 e->inc->z2
# define Z3 e->inc->z3

# define XR1(x) x * cos(TZ)
# define XR2(x) x * cos(TZ + M_PI / 2)

# define YR1(y) y * sin(TZ)
# define YR2(y) y * sin(TZ + M_PI / 2)

# define XA XR1(X1) + XR2(Y1)
# define XB XR1(X2) + XR2(Y1)
# define XC XR1(X1) + XR2(Y2)

# define YA -Z1 + 0.5 * YR1(X1) + 0.5 * YR2(Y1)
# define YB -Z2 + 0.5 * YR1(X2) + 0.5 * YR2(Y1)
# define YC -Z3 + 0.5 * YR1(X1) + 0.5 * YR2(Y2)

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_coord;

typedef struct		s_inc
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z1;
	int				z2;
	int				z3;
	int				color;
}					t_inc;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_inc			*inc;
	t_coord			***coord;
	char			*data;
	void			*img;
	int				color;
	int				bpp;
	int				endian;
	int				size_line;
	int				z;
	int				off;
	int				off2;
	unsigned int	zoom;
	int				zh;
	int				xa;
	int				xb;
	int				xc;
	int				ya;
	int				yb;
	int				yc;
	int				rz;
}					t_env;

typedef struct		s_all
{
	char			**av;
	char			**tab;
	char			**tmp;
	int				x;
	int				y;
}					t_all;

t_coord				*ft_new_coord(int x, int y, int z, int size_x);
t_coord				***ft_get_coord(t_all *all);
int					key_hook(int keycode, t_env *e);
int					main(int ac, char **av);
int					draw(t_env *e);
int					ft_draw_line_x(t_env *e);
int					ft_draw_line_y(t_env *e);
void				get_real_coord(t_env *e);
void				ft_get_tab(t_all *all);
void				ft_mlx(t_env *e);
void				ft_put_pixel(t_env *e, int i, int j);
void				ft_value_color(t_env *e, unsigned int place);
void				ft_color_scale(t_env *e, int x, int y);
void				ft_calc_pixel(t_env *e, int i, int j);

#endif
