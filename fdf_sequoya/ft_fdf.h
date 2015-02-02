/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 15:33:11 by rbaum             #+#    #+#             */
/*   Updated: 2015/02/02 08:04:17 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <fcntl.h>
#include "libft/libft.h"

# define STARTX (200)
# define STARTY (100)
# define INC e->zoom
# define HEIGHT 2000
# define WIDTH 2000
# define OFF e->off
# define YOFF e->off2

# define XA e->inc->x1 - e->inc->y1
# define YA -(e->inc->z) + (e->inc->x1 + e->inc->y1)/2 
# define XB e->inc->x2 - e->inc->y1 
# define YB - (e->inc->z2) + (e->inc->x2 + e->inc->y1)/2 
# define XC e->inc->x1 - e->inc->y2
# define YC - (e->inc->z3) + (e->inc->x1 + e->inc->y2)/2 

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
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		z;
	int		z2;
	int		z3;
	int		color;
	int		color2;

}					t_inc;


typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*content;
	t_coord			***coord;
	t_coord			***real;
	t_inc			*inc;
	int				off;
	int				off2;
	int				zoom;
	int				zh;
}					t_env;


typedef struct		s_all
{
	char			**av;
	char			**tab;
	int				y;
}					t_all;

void		ft_get_tab(t_all *all);
void		ft_get_good_tab(t_all *all);
t_coord		*ft_new_coord(int x, int y, int z, int size_x, int size_y);
t_coord		***ft_get_coord(t_all *all);
void		initial_inc(t_env *e);
void		pixel_put(t_env *e, int i, int j);
void		draw_x(t_env *e);
void		draw_y(t_env *e);
int			draw(t_env *e);
void		iso(t_env *e, t_all *all);
void		vect_AB(int x1, int y1, int x2, int y2, t_env *e);


/*
** Commentaires et choses a faire **

open
◦ read
◦ write
8Projet d’Infographie fdf
◦ close
◦ malloc
◦ free
◦ perror
◦ strerror
◦ exit
◦ toutes les fonctions de la lib math (-lm et man 3 math)
◦ toutes les fonctions de la minilibX bien sûr

************man****************

 mlx_new_window
 mlx_pixel_put
 mlx_new_image
 mlx_loop

 ***********MAKE***************

gcc ft_fdf.c -L/usr/x11/lib -lmlx -lXext -lX11



 */
