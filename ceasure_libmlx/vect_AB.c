/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_AB.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 11:03:51 by cglavieu          #+#    #+#             */
/*   Updated: 2015/01/30 12:20:34 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void vect_AB(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx == 0 || dy == 0)
		crux(x1, y1, x2, y2, c);
	if (dx > 0 && dy > 0 && dx >= dy)
		octant_1(x1, y1, x2, y2, c);
	if (dx > 0 && dy > 0 && dx < dy)
		octant_2(x1, y1, x2, y2, c);
	if (dx < 0 && dy > 0 && -dx < dy)
		octant_3(x1, y1, x2, y2, c);
	if (dx < 0 && dy > 0 && -dx >= dy)
		octant_4(x1, y1, x2, y2, c);
	if (dx < 0 && dy < 0 && dx <= dy)
		octant_5(x1, y1, x2, y2, c);
	if (dx < 0 && dy < 0 && dx > dy)
		octant_6(x1, y1, x2, y2, c);
	if (dx > 0 && dy < 0 && dx < -dy)
		octant_7(x1, y1, x2, y2, c);
	if (dx > 0 && dy < 0 && dx >= -dy)
		octant_8(x1, y1, x2, y2, c);
}