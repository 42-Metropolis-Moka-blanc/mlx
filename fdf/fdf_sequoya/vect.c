#include "ft_fdf.h"

void octant_5(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (x1 != x2)
	{
		mlx_pixel_put(c->mlx, c->win, x1, y1, 0x806D5A);
		e = e - dy;
		if (e >= 0)
		{
			y1--;
			e = e + dx;
		}
		x1--;
	}
}

void octant_6(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (y1 != y2)
	{
		mlx_pixel_put(c->mlx, c->win, x1, y1, 0x800080);
		e = e - dx;
		if (e >= 0)
		{
			x1--;
			e = e + dy;
		}
		y1--;
	}
}

void octant_7(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (y1 != y2)
	{
		mlx_pixel_put(c->mlx, c->win, x1, y1, 0xF0C300);
		e = e + dx;
		if (e > 0)
		{
			x1++;
			e = e + dy;
		}
		y1--;
	}
}

void octant_8(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (x1 != x2)
	{
		mlx_pixel_put(c->mlx, c->win, x1, y1, 0x91283B);
		e = e + dy;
		if (e < 0)
		{
			y1--;
			e = e + dx;
		}
		x1++;
	}
}

void octant_1(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (x1 != x2)
	{
		mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFF0000);
		e = e - dy;
		if (e < 0)
		{
			y1++;
			e = e + dx;
		}
		x1++;
	}
}

void octant_2(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (y1 != y2)
	{
		mlx_pixel_put(c->mlx, c->win, x1, y1, 0x82C46C);
		e = e - dx;
		if (e < 0)
		{
			x1++;
			e = e + dy;
		}
		y1++;
	}
}

void octant_3(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dy;
	dy = e * 2;
	dx = dx * 2;
	while (y1 != y2)
	{
		mlx_pixel_put(c->mlx, c->win, x1, y1, 0xF400A1);
			e = e + dx;
		if (e <= 0)
		{
			x1--;
			e = e + dy;
		}
		y1++;
	}
}

void octant_4(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;
	int e;

	dx = x2 - x1;
	dy = y2 - y1;

	e = dx;
	dx = e * 2;
	dy = dy * 2;
	while (x1 != x2)
	{
		mlx_pixel_put(c->mlx, c->win, x1, y1, 0xAD4F09);
		e = e + dy;
		if (e >= 0)
		{
			y1++;
			e = e + dx;
		}
		x1--;
	}
}

void crux_x(int x1, int y1, int x2, t_env *c)
{
	int dx;

	dx = x2 - x1;
	if (dx > 0)
	{
		while (x1 != x2)
		{
			mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFFFFFF);
			x1++;
		}
	}
	else
	{
		while (x1 != x2)
		{
			mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFFFFFF);
			x1--;
		}
	}
}

void crux_y(int x1, int y1, int y2, t_env *c)
{
	int dy;

	dy = y2 - y1;
	if (dy > 0)
	{
		while (y1 != y2)
		{
			mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFFFFFF);
			y1++;
		}
	}
	else
	{
		while (y1 != y2)
		{
			mlx_pixel_put(c->mlx, c->win, x1, y1, 0xFFFFFF);
			y1--;
		}
	}
}

void crux(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dy == 0)
		crux_x(x1, y1, x2, c);
	if (dx == 0)
		crux_y(x1, y1, y2, c);
}

void vect_AB(int x1, int y1, int x2, int y2, t_env *c)
{
	int dx;
	int dy;

	dx = x2 - x1;
	dy = y2 - y1;
	if (dx == 0 || dy == 0)
		crux(x1, y1, x2, y2, c);
	if (dx > 0 && dy > 0 && dx >= dy)
		octant_1(x1, y1, x2, y2, c);
	if (dx > 0 && dy > 0 && dx < dy)
		octant_2(x1, y1, x2, y2, c);
	if (dx < 0 && dy > 0 && -dx < dy)
		octant_3(x1, y1, x2, y2, c);
	if (dx < 0 && dy > 0 && -dx >= dy)
		octant_4(x1, y1, x2, y2, c);
	if (dx < 0 && dy < 0 && dx <= dy)
		octant_5(x1, y1, x2, y2, c);
	if (dx < 0 && dy < 0 && dx > dy)
		octant_6(x1, y1, x2, y2, c);
	if (dx > 0 && dy < 0 && dx < -dy)
		octant_7(x1, y1, x2, y2, c);
	if (dx > 0 && dy < 0 && dx >= -dy)
		octant_8(x1, y1, x2, y2, c);
}
