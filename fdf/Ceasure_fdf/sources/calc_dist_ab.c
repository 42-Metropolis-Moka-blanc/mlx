/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_ab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 18:04:04 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 20:46:13 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int calc_dist_ab(float x, float y, float x2, float y2)
{
	float	xc;
	float	yc;
	float	t;
	float	r;

	xc = fabsf(x - x2);
	yc = fabsf(y - y2);
	t = xc * xc + yc * yc;
	r = sqrtf(t);
	return (r);
}
