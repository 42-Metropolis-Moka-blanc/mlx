/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel_wput.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 19:28:31 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 03:11:03 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

void mlx_pixel_wput(t_env *e, int x, int y, int color)
{
	unsigned int	place;
	color = color;

	if (x > 0 && x < 1920)
	{
		place = y * (1920 * 4);
		place += x * 4;
		if (place < ((1920 * 1080) * (sizeof(char) * 4)))
		{
			if (e->inc->z != 0)
			{
				e->data[place] = 255;      // bleu
				e->data[place + 1] = 000;  // vert
				e->data[place + 2] = 000;  // rouge
				e->data[place + 3] = 000;  
			}
			else
			{
				e->data[place] = 255;      // bleu
				e->data[place + 1] = 255;  // vert
				e->data[place + 2] = 000;  // rouge
				e->data[place + 3] = 000;  
			}

		}
	}

	// unsigned int	place;

	// if (x > 0 && x < 1920)
	// {
	// 	place = y * (1920 * 4);
	// 	place += x * 4;
	// 	if (place < ((1920 * 1080) * (sizeof(char) * 4)))
	// 	{
	// 		e->data[place] = color;
	// 		e->data[place + 1] = color;
	// 		e->data[place + 2] = color;
	// 		e->data[place + 3] = color;
	// 	}
	// }
}