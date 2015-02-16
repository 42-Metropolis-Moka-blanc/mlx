/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/28 03:47:46 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 11:50:23 by cglavieu         ###   ########.fr       */
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

// void BresenhamLine(int x0, int y0, int x1, int y1) 
// {
// 	int dx, dy, incE, incNE, d, x, y;
// 	dx = x1 - x0; 
// 	dy = y1 - y0;
// 	d = 2*dy - dx;
// 	incE = 2*dy;
// 	incNE = 2*(dy - dx);
// 	x = x0; 
// 	y = y0;
// 	WritePixel(x, y); /* write start pixel */
// 	while (x < x1) 
// 	{
// 		if (d <= 0) /* choose E */
// 			d += incE;
// 		else 
// 		{
// 			d += incNE; /* choose NE */
// 			y++;
// 		}
// 		x++;
// 		WritePixel(x, y);
// 	}
// }