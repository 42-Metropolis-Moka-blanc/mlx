/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 15:47:26 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/01 11:09:06 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void put_ring_ArB(float x, float y, float x2, float y2, t_env *c)
{
	float	i;
	float	r;
	int		xp;
	int		yp;

	i = 0;
	r = calc_dist_AB(x, y, x2, y2);
	while(i < (2*M_PI))
	{
		xp = roundf((x + r*cos(i)));
		yp = roundf((y + r*sin(i)));
		mlx_pixel_put(c->mlx, c->win, xp, yp, 0xFF0000);
		i = i + (2*M_PI/(8*r));
	}
}