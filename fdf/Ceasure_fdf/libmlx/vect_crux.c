/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_crux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 12:03:30 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/15 06:16:07 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void crux_x(int x1, int y1, int x2, t_env *c)
{
	int dx;

	dx = x2 - x1;
	if (dx > 0)
	{
		while (x1 != x2)
		{
			mlx_pixel_wput(c, x1, y1, c->color);
			x1++;
		}
	}
	else
	{
		while (x1 != x2)
		{
			mlx_pixel_wput(c, x1, y1, c->color);
			x1--;
		}
	}
}

void crux_y(int x1, int y1, int y2, t_env *c)
{
	int dy;

	dy = y2 - y1;
	if (dy > 0)
	{
		while (y1 != y2)
		{
			mlx_pixel_wput(c, x1, y1, c->color);
			y1++;
		}
	}
	else
	{
		while (y1 != y2)
		{
			mlx_pixel_wput(c, x1, y1, c->color);
			y1--;
		}
	}
}

void crux(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dy == 0)
		crux_x(x1, y1, x2, c);
	if (dx == 0)
		crux_y(x1, y1, y2, c);
}
