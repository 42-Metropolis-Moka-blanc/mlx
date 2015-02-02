/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 17:28:05 by cglavieu          #+#    #+#             */
/*   Updated: 2015/01/30 12:48:03 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx.h"

int			main(int ac, char **av)
{
	t_env	c;

	(void)ac;
	(void)av;
	c.mlx = mlx_init();
	c.win = mlx_new_window(c.mlx, 1920, 1080, "Hello world !");
	mlx_key_hook(c.win, key_hook, &c);
	mlx_mouse_hook(c.win, mouse_hook, &c);	
	mlx_expose_hook(c.win, expose_base, &c);
	mlx_loop(c.mlx);
	sleep(5);
	return(0);
}