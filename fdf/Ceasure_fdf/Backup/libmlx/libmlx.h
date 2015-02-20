/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 15:52:08 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 13:36:24 by cglavieu         ###   ########.fr       */
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
# define WIDTH 1920
# define HEIGHT 1080
# define XCENTER 960
# define YCENTER 540
# define INC e->zoom
# define OFF 1.00 * e->off
# define YOFF 1.00 * e->off2
# define SX2 e->coord[i + 1][0]->size_x
# define T e->rot
# define S e->roty
# define X1 e->inc->x1
# define Y1 e->inc->y1
# define X2 e->inc->x2
# define Y2 e->inc->y2
# define SIZX e->coord[0][0]->size_x
# define SIZY e->coord[0][0]->size_y
# define CT1 0.5
# define CT2 0.5
# define XAR1(x) (x*(cos(T)))       
# define YAR1(y) (y*(sin(T))*(sin(S)))		
# define XAR2(x) (x*(cos(T+M_PI/2)))     
# define YAR2(y) (y*(sin(T+M_PI/2))*(sin(S)))
# define XA CT1*XAR1(X1) + CT2*XAR2(Y1)
# define YA -((e->inc->z) * sin(S+M_PI/2)) + (CT1/2*YAR1(X1)) + CT2/2*YAR2(Y1)
# define XB CT1*XAR1(X2) + CT2*XAR2(Y1) 
# define YB -((e->inc->z2) * sin(S+M_PI/2)) + CT1/2*YAR1(X2) + CT2/2*YAR2(Y1) 
# define XC CT1*XAR1(X1) + CT2*XAR2(Y2)
# define YC -((e->inc->z3) * sin(S+M_PI/2)) + CT1/2*YAR1(X1) + CT2/2*YAR2(Y2)

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
	void			*img;
	unsigned long	color;
	unsigned long	color2;
	t_coord			***coord;
	t_inc			*inc;
	int				off;
	int				endian;
	int				off2;
	int				zoom;
	int				max_x;
	int				max_y;
	int				zh;
	int				bpp;
	int				s_line;
	int				z;
	float			rot;
	float			roty;
	char			*data;
	// int				*depth;         // A IMPLEMENTER Z BUFFER
}					t_env;

typedef struct        s_all
{
    char            **av;
    char            **tab;
    char            **tmp;
    int                y;
    int                x;
}                  t_map;

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
// void 		BresenhamLine(int x0, int y0, int x1, int y1, t_env *c); 
void 		ring(int x1, int y1, int r, t_env *c);
void		put_ring_ArB(float x, float y, float x2, float y2, t_env *c);
void		vect(float x, float y, float x2, float y2, t_env *c);
void 		ft_mlx(t_env *e);
void		draw(t_env *e);
void		mlx_pixel_wput(t_env *e, int x, int y);
// void		mlx_pixel_wput(t_env *e, int x, int y, int color);
int			calc_dist_AB(float x, float y, float x2, float y2);
int			key_hook(int keycode, t_env *c);
int			mouse_hook(int button, int x, int y, t_env *c);
int			expose_base(t_env *c);
t_coord     ***ft_get_coord(t_map *map);


#endif
