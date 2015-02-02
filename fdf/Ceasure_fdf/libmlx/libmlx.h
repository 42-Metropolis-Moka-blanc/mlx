/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 15:52:08 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/02 11:10:21 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/libft.h"

# define INC e->zoom
# define OFF e->off
# define YOFF e->off2

# define XA e->inc->x1 - e->inc->y1
# define YA -(e->inc->z) + (e->inc->x1 + e->inc->y1)/2 
# define XB e->inc->x2 - e->inc->y1 
# define YB - (e->inc->z2) + (e->inc->x2 + e->inc->y1)/2 
# define XC e->inc->x1 - e->inc->y2
# define YC - (e->inc->z3) + (e->inc->x1 + e->inc->y2)/2

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_coord;

typedef struct   s_coor_box
{
	float	x;
	float	x2;
	float	y;
	float	y2;
	float	xc;
	float	yc;
	float	coeff;
}				 t_box;

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
	t_coord			***coord;
	t_inc			*inc;
	int				off;
	int				off2;
	int				zoom;
	int				zh;
}					t_env;

typedef struct		s_all
{
	char			**av;
	char			**tab;
	int				y;
}					t_map;

void 		crux_x(int x1, int y1, int x2, t_env *c);
void 		crux_y(int x1, int y1, int y2, t_env *c);
void 		crux(int x1, int y1, int x2, int y2, t_env *c);
void 		octant_1(int x1, int y1, int x2, int y2, t_env *c);
void 		octant_2(int x1, int y1, int x2, int y2, t_env *c);
void 		octant_3(int x1, int y1, int x2, int y2, t_env *c);
void 		octant_4(int x1, int y1, int x2, int y2, t_env *c);
void 		octant_5(int x1, int y1, int x2, int y2, t_env *c);
void 		octant_6(int x1, int y1, int x2, int y2, t_env *c);
void 		octant_7(int x1, int y1, int x2, int y2, t_env *c);
void 		octant_8(int x1, int y1, int x2, int y2, t_env *c);
void 		vect_AB(int x1, int y1, int x2, int y2, t_env *c);
void 		ring(int x1, int y1, int r, t_env *c);
void		put_ring_ArB(float x, float y, float x2, float y2, t_env *c);
void		vect(float x, float y, float x2, float y2, t_env *c);
void 		ft_mlx(t_env *e);
void		draw(t_env *e);
int			calc_dist_AB(float x, float y, float x2, float y2);
int			key_hook(int keycode, t_env *c);
int			mouse_hook(int button, int x, int y, t_env *c);
int			expose_base(t_env *c);
t_coord     ***ft_get_coord(t_map *map);


#endif