/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_test_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 18:20:07 by cglavieu          #+#    #+#             */
/*   Updated: 2015/02/16 10:52:50 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libmlx.h"

int			ft_abs(int x)
{
	return (x * (1 - 2 * (x < 0)));
}

int calc_dist_AB(float x, float y, float x2, float y2)
{
	float	xc;
	float	xc2;
	float	yc;
	float	yc2;
	float	t;
	float	r;

	xc = fabsf(x - x2);
	yc = fabsf(y - y2);
	xc2 = xc * xc;
	yc2 = yc * yc;
	t = xc2 + yc2;
	r = sqrtf(t);
	return(r);
}

void trace(int x1, int y1, int x2, int y2, t_env *c)
{
    mlx_pixel_put(c->mlx, c->win, x1 + x2, y1 + y2, 0x82C46C);
    mlx_pixel_put(c->mlx, c->win, x1 + y2, y1 + x2, 0x82C46C);
    mlx_pixel_put(c->mlx, c->win, x1 - x2, y1 + y2, 0x82C46C);
    mlx_pixel_put(c->mlx, c->win, x1 - y2, y1 + x2, 0x82C46C);
    mlx_pixel_put(c->mlx, c->win, x1 + x2, y1 - y2, 0x82C46C);
    mlx_pixel_put(c->mlx, c->win, x1 + y2, y1 - x2, 0x82C46C);
    mlx_pixel_put(c->mlx, c->win, x1 - x2, y1 - y2, 0x82C46C);
    mlx_pixel_put(c->mlx, c->win, x1 - y2, y1 - x2, 0x82C46C);
}

// void put_ring_ArB(float x1, float y1, float r, t_env *c)
// {
//     int x2;
//     int y2;
//     int d;
 
//     x2 = 0;
//     y2 = r;
//     d = r - 1;
//     while(y2 >= x2)
//     {
//         trace(x1, y1, x2, y2, c);
//         if (d >= 2 * x2)
//         {
//             d -= 2 * x2 + 1;
//             x2++;
//         }
//         else if (d < 2 * (r - y2))
//         {
//             d += 2 * y2 - 1;
//             y2--;
//         }
//         else
//         {
//             d+= 2 * (y2 - x2 - 1);
//             y2--;
//             x2++;
//         }
//     }
 
// }


// void put_ring_ArB(float x, float y, float x2, float y2, t_env *c)
// {
// 	float	i;
// 	float	r;
// 	int		xp;
// 	int		yp;

// 	i = 0;
// 	r = calc_dist_AB(x, y, x2, y2);
// 	while(i < (2*M_PI))
// 	{
// 		xp = roundf((x + r*cos(i)));
// 		yp = roundf((y + r*sin(i)));
// 		mlx_pixel_put(c->mlx, c->win, xp, yp, 0xFF0000);
// 		i = i + (2*M_PI/(8*r));
// 	}
// }

// void octant_5(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;
// 	int e;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	e = dx;
// 	dx = e * 2;
// 	dy = dy * 2;
// 	while (x1 != x2)
// 	{
// 		mlx_pixel_put(c->mlx, c->win, x1, y1, 0x806D5A);
// 		e = e - dy;
// 		if (e >= 0)
// 		{
// 			y1--;
// 			e = e + dx;
// 		}
// 		x1--;
// 	}
// }

// void octant_6(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;
// 	int e;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	e = dy;
// 	dy = e * 2;
// 	dx = dx * 2;
// 	while (y1 != y2)
// 	{
// 		mlx_pixel_put(c->mlx, c->win, x1, y1, 0x800080);
// 		e = e - dx;
// 		if (e >= 0)
// 		{
// 			x1--;
// 			e = e + dy;
// 		}
// 		y1--;
// 	}
// }

// void octant_7(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;
// 	int e;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	e = dy;
// 	dy = e * 2;
// 	dx = dx * 2;
// 	while (y1 != y2)
// 	{
// 		mlx_pixel_put(c->mlx, c->win, x1, y1, 0xF0C300);
// 		e = e + dx;
// 		if (e > 0)
// 		{
// 			x1++;
// 			e = e + dy;
// 		}
// 		y1--;
// 	}
// }

// void octant_8(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;
// 	int e;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	e = dx;
// 	dx = e * 2;
// 	dy = dy * 2;
// 	while (x1 != x2)
// 	{
// 		mlx_pixel_put(c->mlx, c->win, x1, y1, 0x91283B);
// 		e = e + dy;
// 		if (e < 0)
// 		{
// 			y1--;
// 			e = e + dx;
// 		}
// 		x1++;
// 	}
// }

// void octant_1(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;
// 	int e;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	e = dx;
// 	dx = e * 2;
// 	dy = dy * 2;
// 	while (x1 != x2)
// 	{
// 		mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFF0000);
// 		e = e - dy;
// 		if (e < 0)
// 		{
// 			y1++;
// 			e = e + dx;
// 		}
// 		x1++;
// 	}
// }

// void octant_2(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;
// 	int e;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	e = dy;
// 	dy = e * 2;
// 	dx = dx * 2;
// 	while (y1 != y2)
// 	{
// 		mlx_pixel_put(c->mlx, c->win, x1, y1, 0x82C46C);
// 		e = e - dx;
// 		if (e < 0)
// 		{
// 			x1++;
// 			e = e + dy;
// 		}
// 		y1++;
// 	}
// }

// void octant_3(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;
// 	int e;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	e = dy;
// 	dy = e * 2;
// 	dx = dx * 2;
// 	while (y1 != y2)
// 	{
// 		mlx_pixel_put(c->mlx, c->win, x1, y1, 0xF400A1);
// 			e = e + dx;
// 		if (e <= 0)
// 		{
// 			x1--;
// 			e = e + dy;
// 		}
// 		y1++;
// 	}
// }

// void octant_4(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;
// 	int e;

// 	dx = x2 - x1;
// 	dy = y2 - y1;

// 	e = dx;
// 	dx = e * 2;
// 	dy = dy * 2;
// 	while (x1 != x2)
// 	{
// 		mlx_pixel_put(c->mlx, c->win, x1, y1, 0xAD4F09);
// 		e = e + dy;
// 		if (e >= 0)
// 		{
// 			y1++;
// 			e = e + dx;
// 		}
// 		x1--;
// 	}
// }

// void crux_x(int x1, int y1, int x2, t_env *c)
// {
// 	int dx;

// 	dx = x2 - x1;
// 	if (dx > 0)
// 	{
// 		while (x1 != x2)
// 		{
// 			mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFFFFFF);
// 			x1++;
// 		}
// 	}
// 	else
// 	{
// 		while (x1 != x2)
// 		{
// 			mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFFFFFF);
// 			x1--;
// 		}
// 	}
// }

// void crux_y(int x1, int y1, int y2, t_env *c)
// {
// 	int dy;

// 	dy = y2 - y1;
// 	if (dy > 0)
// 	{
// 		while (y1 != y2)
// 		{
// 			mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFFFFFF);
// 			y1++;
// 		}
// 	}
// 	else
// 	{
// 		while (y1 != y2)
// 		{
// 			mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFFFFFF);
// 			y1--;
// 		}
// 	}
// }

// void crux(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;

// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	if (dy == 0)
// 		crux_x(x1, y1, x2, c);
// 	if (dx == 0)
// 		crux_y(x1, y1, y2, c);
// }

// void fdf_draw_line(int x1, int y1, int x2, int y2, t_env *c)
// {
// 	int dx;
// 	int dy;

// 	dx = x2 - x1;
// 	dy = y2 - y1;
// 	if (dx == 0 || dy == 0)
// 		crux(x1, y1, x2, y2, c);
// 	if (dx > 0 && dy > 0 && dx >= dy)
// 		octant_1(x1, y1, x2, y2, c);
// 	if (dx > 0 && dy > 0 && dx < dy)
// 		octant_2(x1, y1, x2, y2, c);
// 	if (dx < 0 && dy > 0 && -dx < dy)
// 		octant_3(x1, y1, x2, y2, c);
// 	if (dx < 0 && dy > 0 && -dx >= dy)
// 		octant_4(x1, y1, x2, y2, c);
// 	if (dx < 0 && dy < 0 && dx <= dy)
// 		octant_5(x1, y1, x2, y2, c);
// 	if (dx < 0 && dy < 0 && dx > dy)
// 		octant_6(x1, y1, x2, y2, c);
// 	if (dx > 0 && dy < 0 && dx < -dy)
// 		octant_7(x1, y1, x2, y2, c);
// 	if (dx > 0 && dy < 0 && dx >= -dy)
// 		octant_8(x1, y1, x2, y2, c);
// }


// int        fdf_draw_line(int x1, int y1, int x2, int y2, t_env *d)
// {
//     int dx;
//     int dy;

//     dx = (x2 - x1);
//     dy = (y2 - y1);
//     int color = 0x00FFFFFF;
//     if (ft_abs(dx) > ft_abs(dy))
//         while (dx += (dx < 0) - (dx > 0))
//             mlx_pixel_put(d->mlx, d->win, x1 + dx, y1 + dx * (y2 - y1) / (x2 - x1), color);
//     else
//          while (dy += (dy < 0) - (dy > 0))
//             mlx_pixel_put(d->mlx, d->win, x1 + dy * (x2 - x1) / (y2 - y1), y1 + dy, color);
//     return (0);
// }

void BresenhamLine(int x0, int y0, int x1, int y1, t_env *c) 
{
	int dx, dy, incE, incNE, d, x, y;
	dx = x1 - x0; 
	dy = y1 - y0;
	d = 2*dy - dx;
	incE = 2*dy;
	incNE = 2*(dy - dx);
	x = x0; 
	y = y0;
	mlx_pixel_put(c->mlx, c->win, x, y, 0xAD4F09);
	while (x < x1) 
	{
		if (d <= 0) /* choose E */
			d += incE;
		else 
		{
			d += incNE; /* choose NE */
			y++;
		}
		x++;
		mlx_pixel_put(c->mlx, c->win, x, y, 0xAD4F09);
	}
}

int			key_hook(int keycode, t_env *c)
{
	printf("key : %d\n", keycode);
	if (keycode == 65307)
		exit(0);
	if (keycode == 32)
		mlx_clear_window(c->mlx, c->win);	
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *c)
{
	static	float x_mark;
	static	float y_mark;

int xx;
int yy;
int r;
xx = 960;
yy = 540;
r = 0;

	if (button == 1)
		// fdf_draw_line(x_mark, y_mark, x, y, c);
		BresenhamLine(x_mark, y_mark, x, y, c);
	if (button == 2)
	{
		x_mark = x;
		y_mark = y;
	}
	if (button == 3)
	{
		// r = calc_dist_AB(x_mark, y_mark, x, y);
		while (r < 500)
		{
			// ring(960, 540, r, c);
			r++;
		}
	}
	return (0);
}

int			expose_base(t_env *c)
{
	(void)c;
	return(0);
}


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


