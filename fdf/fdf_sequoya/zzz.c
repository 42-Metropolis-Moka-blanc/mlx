/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zzz.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 16:54:10 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/03 20:09:02 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Initialisation de variable ?? */
#include "ft_fdf.h"

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
	if (keycode == 65453)
		e->zoom -= 1;
	if (keycode == 65451)
		e->zoom += 1;
	if (keycode == 65365)
		e->zh += 1;
	if (keycode == 65366)
		e->zh -= 1;
	expose_hook(e);
	return (0);
}

void ft_mlx(t_env *e)
{

	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
//	mlx_key_hook(e->win, key_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win,KeyPress,KeyRelease, key_hook, e);
	mlx_loop(e->mlx);
}

int main(int ac, char **av)
{
	t_all *all;
	t_env *e;
	if (ac == 1)
		exit(0);
	e = (t_env *)malloc(sizeof(t_env));
	all = (t_all *)malloc(sizeof(t_all));
	e->off = 500;
	e->off2 = 500;
	e->zoom = 42;
	e->zh = 1;
	all->av = av;
	e->coord = ft_get_coord(all);
	ft_mlx(e);
	return (0);
}
/*
libft/libft.a -L/usr/x11/lib -lmlx -lXext -lX11 ft_coord.c  zzz.c draw.c -I /opt/X11/include/X11
*/
