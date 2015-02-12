/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeaujar <bbeaujar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:06:01 by bbeaujar          #+#    #+#             */
/*   Updated: 2015/02/12 13:03:21 by bbeaujar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include <mlx.h>
# include <X.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define STARTX (200)
# define STARTY (100)
# define INC e->zoom
# define HEIGHT 2000
# define WIDTH 2000
# define OFF e->off
# define YOFF e->off2
# define SX1 e->coord[i][0]->size_x
# define SX2 e->coord[i + 1][0]->size_x

typedef struct		s_coord
{
	int				x;
	int				y;
	int				z;
	int				size_x;
	int				size_y;
}					t_coord;

typedef struct		s_inc
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				z;
	int				z2;
	int				z3;
	int				color;
}					t_inc;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_inc			*inc;
	t_coord			***coord;
	char			*data;
	void			*img;
	unsigned long	color;
	int				bpp;
	int				endian;
	int				size_line;
	int				z;
	int				off;
	int				off2;
	int				zoom;
	int				zh;
	int				xa;
	int				xb;
	int				xc;
	int				ya;
	int				yb;
	int				yc;
}					t_env;

typedef struct		s_all
{
	char			**av;
	char			**tab;
	char			**tmp;
	int				x;
	int				y;
}					t_all;

/*	main.c	*/
int					key_hook(int keycode, t_env *e);
void				pixel_put_to_image(t_env *e, int x, int y);
void				ft_mlx(t_env *e);
int					main(int ac, char **av);

/*	ft_coord.c	*/
void				ft_get_tab(t_all *all);
t_coord				*ft_new_coord(int x, int y, int z, int size_x);
t_coord				***ft_get_coord(t_all *all);

/*	ft_pixel_put.c	*/
void				get_real_coord(t_env *e);
int					fdf_draw_line_x(t_env *e);
int					fdf_draw_line_y(t_env *e);
void				ft_put_pixel(t_env *e, int i, int j);

/*	ft_draw.c	*/
int					draw(t_env *e);
void				draw_all(t_env *e);

#endif
