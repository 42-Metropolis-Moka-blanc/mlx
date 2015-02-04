/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 09:57:01 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/04 04:10:25 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

int		fdf_draw_line(int x1, int y1, int x2, int y2, t_env *e)
{
	int dx;
	int dy;
	int color;
	
	color = e->inc->color;
	dx = (x2 - x1);
	dy = (y2 - y1);
	if (abs(dx) > abs(dy))
		while (dx += (dx < 0) - (dx > 0))
			mlx_pixel_put(e->mlx, e->win, x1 + dx,
						  y1 + dx * (y2 - y1) / (x2 - x1), color);
	else
		while (dy += (dy < 0) - (dy > 0))
			mlx_pixel_put(e->mlx, e->win, x1 + dy * (x2 - x1) / (y2 - y1), 
						  y1 + dy, color);
	return (0);
}


void		ft_put_pixel(t_env *e, int i, int j)
{

	if (i < e->coord[0][0]->size_y -1)
		e->inc->z3 = e->coord[i + 1][j]->z;
	else
		e->inc->z3 = e->coord[i][j]->z;
	if (i < e->coord[0][0]->size_y -1)
		e->inc->y2 = (e->coord[i + 1][j]->y * INC);
	else
		e->inc->y2 = (e->coord[i][j]->y * INC);
	if (j < e->coord[i][0]->size_x -1)
		e->inc->x2 = (e->coord[i][j + 1]->x * INC);
	else
		e->inc->x2 = (e->coord[i][j]->x * INC);
	if (j < e->coord[i][0]->size_x -1)
		e->inc->z2 = e->coord[i][j + 1]->z;
	else
		e->inc->z2 = e->coord[i][j]->z;
	e->inc->z = e->coord[i][j]->z;
	e->inc->x1 = (e->coord[i][j]->x  * INC);
	e->inc->y1 = (e->coord[i][j]->y * INC);
	e->inc->z *= e->zh;
	e->inc->z2 *= e->zh;
	e->inc->z3 *= e->zh;
	if (e->coord[i][j]->z != 0)
	{
		vect_AB(XA + OFF, YA + YOFF, XB + OFF, YB + YOFF, e);
		vect_AB(XA + OFF, YA + YOFF, XC + OFF, YC + YOFF, e);
	}
	else
	{
		vect_AB(XA + OFF, YA + YOFF, XB + OFF, YB + YOFF, e);
		vect_AB(XA + OFF, YA + YOFF, XC + OFF, YC +  YOFF, e);
	}	
}

void	draw_all(t_env *e)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	e->inc = malloc(sizeof(t_inc));
	while (i < e->coord[0][0]->size_y )
	{
		j = 0;
		while (j < e->coord[i][0]->size_x )
		{
			if (e->coord[i][j]->z != 0)
				e->inc->color =  0X800080;
			else
				e->inc->color =  0X048B9A;
			ft_put_pixel(e, i,j);
			j++;
		}
		i++;
	}
}


int	 draw(t_env *e)
{
	draw_all(e);
	return (0);
}
