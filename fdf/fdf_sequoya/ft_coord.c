/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 11:29:56 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/04 07:01:53 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void        ft_get_tab(t_all *all)
{
	int     fd;
	int     i;
	char    *line;

	all->y = 0;
	i = 0;
	if ((fd = open(all->av[1], O_RDONLY)) < 0)
	{
		ft_putendl("Cannot open Map");
		exit(0);
	}
	while (get_next_line(fd, &line))
			all->y++;
	close(fd);
	fd = open(all->av[1], O_RDONLY);
	all->tab = (char **)malloc(sizeof(char *) * (all->y + 1));
	while (get_next_line(fd, &line))
	{
		if (line[0] != '\0')
		{
			all->tab[i++] = line;
		ft_putendl(all->tab[i - 1]);
		}
		else
			all->y--;
			
	}
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
	coord->x = x;
	if (y >= 1)
		coord->y = y;
	return (coord);
}

t_coord     ***ft_get_coord(t_all *all)
{
	int     i;
	int     j;
	char    **tmp;
	int     size_x;
	t_coord ***coord;

	i = 0;
	ft_get_tab(all);
 	coord = (t_coord ***)malloc(sizeof(t_coord **) * all->y + 1); 
	while (i < all->y)
	{
		tmp = ft_strsplit(all->tab[i], ' ');
		size_x = 0;
		if (tmp[size_x] == 0) 
			size_x++;
		while (tmp[size_x] != '\0')
			size_x++;
		j = -1;
		coord[i] = (t_coord **)malloc(sizeof(t_coord*) * (size_x + 1));
		while (++j < size_x)
		{
			if (tmp[j] != '\0' && tmp[j][0] != '\n')
				coord[i][j] = ft_new_coord(j, i, ft_atoi(tmp[j]), size_x, all->y);
		}
		free(tmp);
		i++; 
 	} 
	tmp = NULL;
	return (coord);
}

/*
		if (tmp == NULL)
		{
			ft_putendl("wrong map");
			exit(0);
		}
*/
