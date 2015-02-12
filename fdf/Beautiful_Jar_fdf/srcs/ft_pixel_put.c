/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 09:56:17 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/02/12 11:47:21 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	get_real_coord(t_env *e)
{
	e->xa = e->inc->x1 - e->inc->y1 + OFF;
	e->xb = e->inc->x2 - e->inc->y1 + OFF;
	e->xc = e->inc->x1 - e->inc->y2 + OFF;
	e->ya = -(e->inc->z) + (e->inc->x1 + e->inc->y1) / 2 + YOFF;
	e->yb = -(e->inc->z) + (e->inc->x2 + e->inc->y1) / 2 + YOFF;
	e->yc = -(e->inc->z) + (e->inc->x1 + e->inc->y2) / 2 + YOFF;
}

int		fdf_draw_line_x(t_env *e)
{
	int		dx;
	int		dy;

	get_real_coord(e);
	color = e->inc->color;
	dx = (e->xb - e->xa);
	dy = (e->yb - e->ya);
	if (abs(dx) > abs(dy))
		while (dx += (dx < 0) - (dx > 0))
			pixel_put_to_image(e, e->inc->x1 + dx, e->inc->y1 + dx *
					(e->inc->y2 - e->inc->y1) / (e->inc->x2 - e->inc->x1));
	else
		while (dy += (dy < 0) - (dy > 0))
			pixel_put_to_image(e, e->inc->x1 + dy * (e->inc->x2 - e->inc->x1) /
					(e->inc->y2 - e->inc->y1), e->inc->y1 + dy);
	return (0);
}

int		fdf_draw_line_y(t_env *e)
{
	int		dx;
	int		dy;

	get_real_coord(e);
	color = e->inc->color;
	dy = (e->xc - e->xa);
	dx = (e->yc - e->ya);
	if (abs(dx) > abs(dy))
		while (dx += (dx < 0) - (dx > 0))
			pixel_put_to_image(e, e->inc->x1 + dx, e->inc->y1 + dx *
					(e->inc->y2 - e->inc->y1) / (e->inc->x2 - e->inc->x1));
	else
		while (dy += (dy < 0) - (dy > 0))
			pixel_put_to_image(e, e->inc->x1 + dy * (e->inc->x2 - e->inc->x1) /
					(e->inc->y2 - e->inc->y1), e->inc->y1 + dy);
	return (0);
}

void	ft_put_pixel(t_env *e, int i, int j)
{
	e = e;
	i = i;
	j = j;
	ft_calc_pixel(e, i, j);
	if (e->coord[i][j]->z != 0)
	{
		e->inc->color = e->coord[i][j]->z > 0 ? 0X318CE7 : 0XFF4901;
		fdf_draw_line_x(e);
		fdf_draw_line_y(e);
	}
	else
	{
		e->inc->color = 0X800080;
		fdf_draw_line_x(e);
		fdf_draw_line_y(e);
	}
}
