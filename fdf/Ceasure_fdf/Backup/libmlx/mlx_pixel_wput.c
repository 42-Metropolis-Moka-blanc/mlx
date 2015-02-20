/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_wput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 19:28:31 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 12:53:57 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void mlx_pixel_wput(t_env *e, int x, int y)
{
	unsigned int	place;
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char r2;
	unsigned char g2;
	unsigned char b2;

	r = (e->color & 0xFF0000) >> 16;
	g = (e->color & 0xFF00) >> 8;
	b = (e->color & 0xFF);
	r2 = (e->color2 & 0xFF0000) >> 16;
	g2 = (e->color2 & 0xFF00) >> 8;
	b2 = (e->color2 & 0xFF);
	if (x > 0 && x < 1920)
	{
		place = y * (1920 * 4);
		place += x * 4;
		if (place < ((WIDTH * HEIGHT) * (sizeof(char) * 4)))
		{
			if (e->inc->z <= 0 && e->inc->z2 <= 0 && e->inc->z3 <= 0)
			{
				e->data[place] = b;
				e->data[place + 1] = g;
				e->data[place + 2] = r;
			}
			else
			{
				e->data[place] = b2;
				e->data[place + 1] = g2;
				e->data[place + 2] = r2;
			}
		}
	}
}
