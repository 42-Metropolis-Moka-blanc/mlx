/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 15:52:08 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/01 11:00:29 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMLX_H
# define LIBMLX_H

#include <mlx.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

typedef struct   s_env
{
	void	*mlx;
	void	*win;
}				 t_env;

void crux_x(int x1, int y1, int x2, t_env *c);
void crux_y(int x1, int y1, int y2, t_env *c);
void crux(int x1, int y1, int x2, int y2, t_env *c);
void octant_1(int x1, int y1, int x2, int y2, t_env *c);
void octant_2(int x1, int y1, int x2, int y2, t_env *c);
void octant_3(int x1, int y1, int x2, int y2, t_env *c);
void octant_4(int x1, int y1, int x2, int y2, t_env *c);
void octant_5(int x1, int y1, int x2, int y2, t_env *c);
void octant_6(int x1, int y1, int x2, int y2, t_env *c);
void octant_7(int x1, int y1, int x2, int y2, t_env *c);
void octant_8(int x1, int y1, int x2, int y2, t_env *c);
void vect_AB(int x1, int y1, int x2, int y2, t_env *c);
void ring(int x1, int y1, int r, t_env *c);
void		put_ring_ArB(float x, float y, float x2, float y2, t_env *c);
void		vect(float x, float y, float x2, float y2, t_env *c);
int			calc_dist_AB(float x, float y, float x2, float y2);
int			key_hook(int keycode, t_env *c);
int			mouse_hook(int button, int x, int y, t_env *c);
int			expose_base(t_env *c);


#endif