/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 10:29:44 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 20:50:45 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"
#define BOX c->box->

void trace(t_env *c)
{
	mlx_pixel_put(c->mlx, c->win, BOXx + BOXx2, BOXy + BOXy2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, BOXx + BOXy2, BOXy + BOXx2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, BOXx - BOXx2, BOXy + BOXy2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, BOXx - BOXy2, BOXy + BOXx2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, BOXx + BOXx2, BOXy - BOXy2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, BOXx + BOXy2, BOXy - BOXx2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, BOXx - BOXx2, BOXy - BOXy2, 0x82C46C);
	mlx_pixel_put(c->mlx, c->win, BOXx - BOXy2, BOXy - BOXx2, 0x82C46C);
}

void ring(t_env *c)
{
	int d;

	BOXx2 = 0;
	BOXy2 = r;
	d = r - 1;
	while (BOXy2 >= BOXx2)
	{
		trace(c);
		if (d >= 2 * BOXx2)
		{
			d -= 2 * BOXx2 + 1;
			BOXx2++;
		}
		else if (d < 2 * (r - BOXy2))
		{
			d += 2 * BOXy2 - 1;
			BOXy2--;
		}
		else
		{
			d += 2 * (BOXy2 - BOXx2 - 1);
			BOXy2--;
			BOXx2++;
		}
	}
}
