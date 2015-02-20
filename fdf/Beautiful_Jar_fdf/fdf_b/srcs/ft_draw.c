/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/04 09:56:17 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/02/20 18:07:22 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	ft_calc_pixel(t_env *e, int i, int j)
{
	if (i < e->coord[0][0]->size_y - 1 && j < e->coord[i + 1][0]->size_x)
		e->inc->z3 = e->coord[i + 1][j]->z;
	else
		e->inc->z3 = e->coord[i][j]->z;
	if (i < e->coord[0][0]->size_y - 1 && j < e->coord[i + 1][0]->size_x)
		e->inc->y2 = (e->coord[i + 1][j]->y * e->zoom);
	else
		e->inc->y2 = (e->coord[i][j]->y * e->zoom);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->x2 = (e->coord[i][j + 1]->x * e->zoom);
	else
		e->inc->x2 = (e->coord[i][j]->x * e->zoom);
	if (j < e->coord[i][0]->size_x - 1)
		e->inc->z2 = e->coord[i][j + 1]->z;
	else
		e->inc->z2 = e->coord[i][j]->z;
	e->inc->z1 = e->coord[i][j]->z * e->zh;
	e->inc->x1 = (e->coord[i][j]->x * e->zoom);
	e->inc->y1 = (e->coord[i][j]->y * e->zoom);
	e->inc->z2 *= e->zh;
	e->inc->z3 *= e->zh;
}

void	ft_color_scale(t_env *e, int x, int y)
{
	unsigned int place;

	if (x > 0 && x < WIDTH)
	{
		place = y * (WIDTH * 4);
		place += x * 4;
		if (place < ((WIDTH * HEIGHT) * (sizeof(char) * 4)))
			ft_value_color(e, place);
	}
}

void	ft_value_color(t_env *e, unsigned int place)
{
	if (e->inc->z1 == 0)
	{
		e->data[place] = 231;
		e->data[place + 1] = 140;
		e->data[place + 2] = 49;
	}
	else if (e->inc->z1 > 0)
	{
		e->data[place] = 1;
		e->data[place + 1] = 73;
		e->data[place + 2] = 255;
	}
	else
	{
		e->data[place] = 78;
		e->data[place + 1] = 184;
		e->data[place + 2] = 22;
	}
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
