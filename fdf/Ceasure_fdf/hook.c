/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:29:54 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/02 11:19:28 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/libmlx.h"

int expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
		mlx_clear_window(e->mlx, e->win);
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
	expose_hook(e);
	return (0);
}

void ft_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, 1920, 1080, "fdf");
	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
}