/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 10:32:09 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/15 07:36:45 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmlx/libmlx.h"

void        ft_get_tab(t_map *map)
{
	int     fd;
	int     i;
	char    *line;

	map->y = 0;
	i = 0;
	if ((fd = open(map->av[1], O_RDONLY)) < 0)
	{
		exit(0);
	}
	while (get_next_line(fd, &line))
		map->y++;
	close(fd);
	fd = open(map->av[1], O_RDONLY);
	map->tab = (char **)malloc(sizeof(char *) * (map->y + 1));
	while (get_next_line(fd, &line))
		map->tab[i++] = line;
	close(fd);
}

t_coord     *ft_new_coord(int x, int y, int z, int size_x, int size_y)
{
	t_coord *coord;

	coord = (t_coord *)malloc(sizeof(t_coord));
	if (coord == NULL)
		return (NULL);
	coord->size_x = (size_x);
	coord->size_y = (size_y);
	coord->z = z;
	coord->x = x - size_x/2;//   MUAHAHAHAHAHAAAAAAA !!!!!
	coord->y = y - size_y/2;//   MUAHAHAHAHAHAAAAAAA !!!!!
	return (coord);
}

t_coord     ***ft_get_coord(t_map *map)
{
	int     i;
	int     j;
	char    **tmp;
	int     tmp_size;
	t_coord ***coord;

	i = 0;
	ft_get_tab(map);
	coord = (t_coord ***)malloc(sizeof(t_coord **) * map->y + 1);
	while (i < map->y)
	{
		tmp = ft_strsplit(map->tab[i], ' ');
		tmp_size = 0;
		while (tmp[tmp_size] != '\0')
			tmp_size++;
		coord[i] = (t_coord **)malloc(sizeof(t_coord*) * (tmp_size + 1));
		j = -1;
		while (++j < tmp_size)
			coord[i][j] = ft_new_coord(j, i, ft_atoi(tmp[j]), tmp_size, map->y);
		free(tmp);
		i++;
	}
	tmp = NULL;
	return (coord);
}