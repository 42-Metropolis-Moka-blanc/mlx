/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 09:57:01 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/02 10:13:33 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_fdf.h"

void	initial_inc(t_env *e)
{
	e->inc->x1 = 0;
	e->inc->x2 = 0;
	e->inc->y1 = 0;
	e->inc->y2 = 0;
	e->inc->color =  0X800080;
	e->inc->color2 =  0X048B9A;
}

int        fdf_draw_line(int x1, int y1, int x2, int y2, t_env *e, int color)
{
    int dx;
    int dy;

    dx = (x2 - x1);
    dy = (y2 - y1);
    if (abs(dx) > abs(dy))
        while (dx += (dx < 0) - (dx > 0))
            mlx_pixel_put(e->mlx, e->win, x1 + dx, y1 + dx * (y2 - y1) / (x2 - x1), color);
    else
        while (dy += (dy < 0) - (dy > 0))
            mlx_pixel_put(e->mlx, e->win, x1 + dy * (x2 - x1) / (y2 - y1), y1 + dy, color);
    return (0);
}


void	draw_all(t_env *e)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	e->inc = malloc(sizeof(t_inc));
	initial_inc(e);
	while (i < e->coord[0][0]->size_y -1)
	{
		j = 0;
		while (j < e->coord[i][0]->size_x -1)
		{
			e->inc->z3 = e->coord[i + 1][j]->z;
			e->inc->y2 = (e->coord[i + 1][j]->y * INC);
			e->inc->x2 = (e->coord[i][j + 1]->x * INC);
			e->inc->z = e->coord[i][j]->z;
			e->inc->z2 = e->coord[i][j + 1]->z;
			e->inc->x1 = (e->coord[i][j]->x  * INC);
			e->inc->y1 = (e->coord[i][j]->y * INC);
			e->inc->z *= e->zh;
			e->inc->z2 *= e->zh;
			e->inc->z3 *= e->zh;
			if (e->coord[i][j]->z != 0)
			{
				fdf_draw_line(XA + OFF, YA + YOFF, XB + OFF, YB + YOFF, e, e->inc->color);
				fdf_draw_line(XA + OFF, YA + YOFF, XC + OFF, YC + YOFF, e, e->inc->color);
			}	
			else
			{
				fdf_draw_line(XA + OFF, YA + YOFF, XB + OFF, YB + YOFF, e, e->inc->color2);
				fdf_draw_line(XA + OFF, YA + YOFF, XC + OFF, YC +  YOFF, e, e->inc->color2);
			}	
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
