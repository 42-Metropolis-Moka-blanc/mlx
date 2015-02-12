/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 09:56:17 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/02/12 11:22:20 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_calc_pixel(t_env *e, int i, int j)
{
	if (i < e->coord[0][0]->size_y - 1 && j < SX2)
		e->inc->z3 = e->coord[i + 1][j]->z;
	else
		e->inc->z3 = e->coord[i][j]->z;
	if (i < e->coord[0][0]->size_y - 1 && j < SX2)
		e->inc->y2 = (e->coord[i + 1][j]->y * INC);
	else
		e->inc->y2 = (e->coord[i][j]->y * INC);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->x2 = (e->coord[i][j + 1]->x * INC);
	else
		e->inc->x2 = (e->coord[i][j]->x * INC);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->z2 = e->coord[i][j + 1]->z;
	else
		e->inc->z2 = e->coord[i][j]->z;
	e->inc->z = e->coord[i][j]->z * e->zh;
	e->inc->x1 = (e->coord[i][j]->x * INC);
	e->inc->y1 = (e->coord[i][j]->y * INC);
	e->inc->z2 *= e->zh;
	e->inc->z3 *= e->zh;
}

int		draw(t_env *e)
{
	int i;
	int j;

	i = 0;
	j = 0;
	e->inc = malloc(sizeof(t_inc));
	while (i < e->coord[0][0]->size_y)
	{
		j = 0;
		while (j < e->coord[i][0]->size_x)
		{
			ft_put_pixel(e, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
