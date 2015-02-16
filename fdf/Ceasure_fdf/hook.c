/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:29:54 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 01:43:21 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <X.h>
#include "libmlx/libmlx.h"

int loop_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, 1920, 1080);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line),
								&(e->endian));
	e->rot += (2*M_PI/1080);
	draw(e);
	// if (e->img)
	// 	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	// mlx_destroy_image(e->mlx, e->img);
	// usleep(50000);
	return(0);
}

int expose_hook(t_env *e)
{
	draw(e);
	// if (e->img)
	// 	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	// mlx_clear_window(e->mlx, e->win);

	if (keycode == 65307)
		exit(0);
	if (keycode == 65361)
		e->off -= 10;
	if (keycode == 65363)
		e->off += 10;
	if (keycode == 65362)
		e->off2 -= 10;
	if (keycode == 65364)
		e->off2 += 10;
	if (keycode == 46)
		e->zoom -= 1;
	if (keycode == 44)
		e->zoom += 1;
	if (keycode == 65365)
		e->zh += 2;
	if (keycode == 65366)
		e->zh -= 2;
	if (keycode == 97)
		e->rot += (2*M_PI/360);
	if (keycode == 100)
		e->rot -= (2*M_PI/360);
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, 1920, 1080);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line),
								&(e->endian));
	expose_hook(e);
	return (0);
}

void ft_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1920, 1080, "fdf");
	e->img = mlx_new_image(e->mlx, 1920, 1080);
	e->bpp = 4;
	e->endian = 1;
	e->s_line = 1920;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_line), &(e->endian));
	e->color = mlx_get_color_value(e->mlx, e->color);
	// mlx_key_hook(e->win, key_hook, e);
	mlx_hook(e->win,KeyPress,KeyRelease, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	// mlx_loop_hook (e->mlx, loop_hook, e);
	mlx_loop(e->mlx);
}
