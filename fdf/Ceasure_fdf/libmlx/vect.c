/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 03:47:46 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/13 20:31:19 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void x_based_line(t_box coor, t_env *c)
{
	while (coor.xc != coor.x)
	{
		mlx_pixel_put(c->mlx, c->win, coor.xc, coor.yc, 0xFF0000);
		coor.yc = coor.coeff * (coor.xc - coor.x2) + coor.y2; 
		if (coor.x < coor.xc)
			coor.xc--;
		else
			coor.xc++;
	}
}

void y_based_line(t_box coor, t_env *c)
{  
	while (coor.yc != coor.y)
	{
		mlx_pixel_put(c->mlx, c->win, coor.xc, coor.yc, 0xFF0000);
		coor.xc = ((coor.yc / coor.coeff) - coor.y2 / coor.coeff) + coor.x2; 
		if (coor.y < coor.yc)
			coor.yc--;
		else
			coor.yc++;
	}
}

void		vect(float x, float y, float x2, float y2, t_env *c)
{	
	t_box   coor;
	
	coor.x2 = x;
	coor.x = x2;
	coor.y2 = y;
	coor.y = y2;
	coor.xc = x;
	coor.yc = y;
	coor.coeff = (y - y2) / (x - x2);
	if ((x-x2)/(y-y2) > 1 || (x-x2)/(y-y2) < -1)
		x_based_line(coor, c);
	else
		y_based_line(coor, c);
}