/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 18:13:17 by cglavieu          #+#    #+#             */
/*   Updated: 2015/01/29 19:55:40 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx.h"

int			key_hook(int keycode, t_env *c)
{
	printf("key : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	// if (keycode == /**/)
	// 	/**/;
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *c)
{
	static	float x_mark;
	static	float y_mark;

	printf("mouse: %d (%d:%d)\n", button, x, y);
	if (button == 1)
		/**/;
	// if (button == 2)
	// 	/**/;
	// if (button == 3)
	// 	/**/;
	return (0);
}

int			expose_base(t_env *c)
{	
	float x;

	x = 961;
	while (x < 1600)
	{
		put_ring_ArB(960, 540, x, 540, c);
		x++;
	}
	return(0);
}