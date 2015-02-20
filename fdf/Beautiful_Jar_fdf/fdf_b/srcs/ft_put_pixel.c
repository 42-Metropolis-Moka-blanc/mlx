/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_pixel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 09:56:17 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/02/20 18:27:05 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
/*
void	get_real_coord(t_env *e)
{
	e->xa = e->inc->x1 - e->inc->y1 + e->off;
	e->xb = e->inc->x2 - e->inc->y1 + e->off;
	e->xc = e->inc->x1 - e->inc->y2 + e->off;
	e->ya = -(e->inc->z1) + (e->inc->x1 + e->inc->y1) / 2 + e->off2;
	e->yb = -(e->inc->z2) + (e->inc->x2 + e->inc->y1) / 2 + e->off2;
	e->yc = -(e->inc->z3) + (e->inc->x1 + e->inc->y2) / 2 + e->off2;
}
*/
int		ft_draw_line_x(t_env *e)
{
	int		dx;
	int		dy;

//	get_real_coord(e);
	dx = (XB - XA);
	dy = (YB - YA);
	if (abs(dx) > abs(dy))
		while (dx += (dx < 0) - (dx > 0))
			ft_color_scale(e, XA + dx, YA + dx * dy / (XB - XA));
	else
		while (dy += (dy < 0) - (dy > 0))
			ft_color_scale(e, XA + dy * dx / (YB - YA), YA + dy);
	return (0);
}

int		ft_draw_line_y(t_env *e)
{
	int		dx;
	int		dy;

//	get_real_coord(e);
	dx = (XC - XA);
	dy = (YC - YA);
	if (abs(dx) > abs(dy))
		while (dx += (dx < 0) - (dx > 0))
			ft_color_scale(e, XA + dx, YA + dx * (YC - YA) / (XC - XA));
	else
		while (dy += (dy < 0) - (dy > 0))
			ft_color_scale(e, XA + dy * (XC - XA) / (YC - YA), YA + dy);
	return (0);
}

void	ft_put_pixel(t_env *e, int i, int j)
{
	ft_calc_pixel(e, i, j);
	ft_draw_line_x(e);
	//ft_draw_line_y(e);
}
