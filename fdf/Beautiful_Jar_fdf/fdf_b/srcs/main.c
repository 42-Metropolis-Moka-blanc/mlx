/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 22:01:58 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/02/20 18:30:06 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int		expose_hook(t_env *e)
{
	draw(e);
	if (e->img)
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
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
	mlx_destroy_image(e->mlx, e->img);
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line),
								&(e->endian));
	expose_hook(e);
	return (0);
}

void	ft_mlx(t_env *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "fdf");
	e->img = mlx_new_image(e->mlx, WIDTH, HEIGHT);
	e->coord[0][0]->x = 0;
	e->coord[0][0]->y = 0;
	e->bpp = 4;
	e->endian = 1;
	e->size_line = WIDTH;
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line),
								&(e->endian));
	e->color = mlx_get_color_value(e->mlx, e->color);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_hook(e->win, KeyPress, KeyRelease, key_hook, e);
	mlx_loop(e->mlx);
}

int		main(int ac, char **av)
{
	t_all	*all;
	t_env	*e;

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
