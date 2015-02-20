/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:39:36 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 14:04:16 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/libmlx.h"

void	ft_calc_pixel(t_env *e, int i, int j)
{
	if (i < e->coord[0][0]->size_y - 1 && j < SX2)
		e->inc->z3 = e->coord[i + 1][j]->z;
	else
		e->inc->z3 = e->coord[i][j]->z;
	if (i < e->coord[0][0]->size_y - 1 && j < SX2)
		e->inc->y2 = (e->coord[i + 1][j]->y * INC);
	else
		e->inc->y2 = (e->coord[i][j]->y * INC);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->x2 = (e->coord[i][j + 1]->x * INC);
	else
		e->inc->x2 = (e->coord[i][j]->x * INC);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->z2 = e->coord[i][j + 1]->z;
	else
		e->inc->z2 = e->coord[i][j]->z;
	e->inc->z = e->coord[i][j]->z * e->zh;
	e->inc->x1 = (e->coord[i][j]->x * INC);
	e->inc->y1 = (e->coord[i][j]->y * INC);
	e->inc->z2 *= e->zh;
	e->inc->z3 *= e->zh;
}

void	ft_put_pixel(t_env *e, int i, int j)
{
	e = e;
	i = i;
	j = j;
	ft_calc_pixel(e, i, j);
	vect_AB(XA + OFF, YA + YOFF, XB + OFF, YB + YOFF, e);
	if (e->coord[0][0]->size_y > 1)
	vect_AB(XA + OFF, YA + YOFF, XC + OFF, YC + YOFF, e);
}

void	draw(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if ((e->inc = malloc(sizeof(t_inc))) == NULL)
		exit(0);
	while (i < e->coord[0][0]->size_y)
	{
		j = 0;
		while (j < e->coord[i][0]->size_x)
		{
			ft_put_pixel(e, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
