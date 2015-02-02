/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:39:36 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/02 10:43:29 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/libmlx.h"

void	initial_inc(t_env *e)
{
	e->inc->x1 = 0;
	e->inc->x2 = 0;
	e->inc->y1 = 0;
	e->inc->y2 = 0;
	e->inc->color =  0X800080;
	e->inc->color2 =  0X048B9A;
}

void	draw(t_env *e)
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
				vect_AB(XA + OFF, YA + YOFF, XB + OFF, YB + YOFF, e);
				vect_AB(XA + OFF, YA + YOFF, XC + OFF, YC + YOFF, e);
			}	
			else
			{
				vect_AB(XA + OFF, YA + YOFF, XB + OFF, YB + YOFF, e);
				vect_AB(XA + OFF, YA + YOFF, XC + OFF, YC +  YOFF, e);
			}	
			j++;
		}
		i++;
	}
}