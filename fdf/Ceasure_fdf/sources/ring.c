/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 15:47:26 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 20:47:30 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void put_ring_arb(t_env *c)
{
	float	i;
	float	r;
	int		xp;
	int		yp;

	i = 0;
	r = calc_dist_AB(c->box->x, c->box->y, c->box->x2, c->box->y2);
	while (i < (2 * M_PI))
	{
		xp = roundf((c->box->x + r * cos(i)));
		yp = roundf((c->box->y + r * sin(i)));
		mlx_pixel_put(c->mlx, c->win, xp, yp, 0xFF0000);
		i = i + (2 * M_PI / (8 * r));
	}
}
