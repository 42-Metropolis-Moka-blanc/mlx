/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:33:11 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/04 06:29:04 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H
# include <math.h>
# include <X.h>
# include <mlx.h>
# include <fcntl.h>
# include "libft/libft.h"

# define STARTX (200)
# define STARTY (100)
# define INC e->zoom
# define HEIGHT 2000
# define WIDTH 2000
# define OFF e->off
# define YOFF e->off2
# define SX1 e->coord[i][0]->size_x
# define SX2 e->coord[i + 1][0]->size_x
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
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		z;
	int		z2;
	int		z3;
	int		color;
	int		color2;
}					t_inc;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*content;
	t_coord			***coord;
	t_inc			*inc;
	int				off;
	int				off2;
	int				zoom;
	int				zh;
	int				xa;
	int				xb;
	int				xc;
	int				ya;
	int				yb;
	int				yc;
}					t_env;

typedef struct		s_all
{
	char			**av;
	char			**tab;
	int				y;
}					t_all;

void		ft_get_tab(t_all *all);
void		ft_get_good_tab(t_all *all);
t_coord		*ft_new_coord(int x, int y, int z, int size_x, int size_y);
t_coord		***ft_get_coord(t_all *all);
void		initial_inc(t_env *e, int i, int j);
void		pixel_put(t_env *e, int i, int j);
void		draw_x(t_env *e);
void		draw_y(t_env *e);
int			draw(t_env *e);
void		iso(t_env *e, t_all *all);
void		vect_AB(int x1, int y1, int x2, int y2, t_env *e);
void		ft_put_pixel(t_env *e, int i, int j);
void		ft_calc_pixel(t_env *e, int i, int j);
int			fdf_draw_line_t1(t_env *e);
int			fdf_draw_line_t2(t_env *e);

#endif
