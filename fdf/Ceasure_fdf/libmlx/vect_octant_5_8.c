/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_octant_5_8.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 12:08:17 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/15 06:17:03 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void octant_5(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (x1 != x2)
	{
		mlx_pixel_wput(c, x1, y1, c->color);
		e = e - dy;
		if (e >= 0)
		{
			y1--;
			e = e + dx;
		}
		x1--;
	}
}

void octant_6(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (y1 != y2)
	{
		mlx_pixel_wput(c, x1, y1, c->color);
		e = e - dx;
		if (e >= 0)
		{
			x1--;
			e = e + dy;
		}
		y1--;
	}
}

void octant_7(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (y1 != y2)
	{
		mlx_pixel_wput(c, x1, y1, c->color);
		e = e + dx;
		if (e > 0)
		{
			x1++;
			e = e + dy;
		}
		y1--;
	}
}

void octant_8(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (x1 != x2)
	{
		mlx_pixel_wput(c, x1, y1, c->color);
		e = e + dy;
		if (e < 0)
		{
			y1--;
			e = e + dx;
		}
		x1++;
	}
}
