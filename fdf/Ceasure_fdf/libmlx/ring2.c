/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:29:44 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/01 11:06:05 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void trace(int x1, int y1, int x2, int y2, t_env *c)
{
	mlx_pixel_put(c->mlx, c->win, x1 + x2, y1 + y2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, x1 + y2, y1 + x2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, x1 - x2, y1 + y2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, x1 - y2, y1 + x2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, x1 + x2, y1 - y2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, x1 + y2, y1 - x2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, x1 - x2, y1 - y2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, x1 - y2, y1 - x2, 0x82C46C);
}

void ring(int x1, int y1, int r, t_env *c)
{
	int x2;
	int y2;
	int d;
 
	x2 = 0;
	y2 = r;
	d = r - 1;
	while(y2 >= x2)
	{
		trace(x1, y1, x2, y2, c);
		if (d >= 2 * x2)
		{
			d -= 2 * x2 + 1;
			x2++;
		}
		else if (d < 2 * (r - y2))
		{
			d += 2 * y2 - 1;
			y2--;
		}
		else
		{
			d += 2 * (y2 - x2 - 1);
			y2--;
			x2++;
		}
	}
}