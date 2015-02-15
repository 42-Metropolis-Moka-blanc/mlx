/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:22:12 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/02 14:54:07 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/libmlx.h"

int main(int ac, char **av)
{
	t_map *map;
	t_env *c;
	if (ac == 1)
		exit(0);
	c = (t_env *)malloc(sizeof(t_env));
	map = (t_map *)malloc(sizeof(t_map));
	c->off = 960;
	c->off2 = 540;
	c->zoom = 42;
	c->zh = 1;
	c->rot = 0;
	map->av = av;
	c->coord = ft_get_coord(map);
	ft_mlx(c);
	return (0);
}