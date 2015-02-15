/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:39:36 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/15 06:27:39 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/libmlx.h"

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
		vect_AB(XA + OFF, YA + YOFF, XC + OFF, YC + YOFF, e);
	}
}

void	draw(t_env *e)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	// e->bpp = 4;
	// e->s_line = 1920;
	// e->endian = 1;
	// // e->img = mlx_new_image(e->mlx, 1920, 1080);
	// mlx_destroy_image(e->mlx, e->img);
	// e->data = mlx_get_data_addr(e->img, &e->bpp, &e->s_line, &e->endian);
	e->inc = malloc(sizeof(t_inc));
	while (i < e->coord[0][0]->size_y)
	{
		j = 0;
		while (j < e->coord[i][0]->size_x )
		{
			if (e->coord[i][j]->z != 0)
				e->inc->color =  0X800080;
			else
				e->inc->color =  0X048B9A;
			ft_put_pixel(e, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
