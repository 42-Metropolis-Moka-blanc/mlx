/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_AB.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 18:04:04 by cglavieu          #+#    #+#             */
/*   Updated: 2015/01/29 18:27:43 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int calc_dist_AB(float x, float y, float x2, float y2)
{
	float	xc;
	float	xc2;
	float	yc;
	float	yc2;
	float	t;
	float	r;

	xc = fabsf(x - x2);
	yc = fabsf(y - y2);
	xc2 = xc * xc;
	yc2 = yc * yc;
	t = xc2 + yc2;
	r = sqrtf(t);
	return(r);
}