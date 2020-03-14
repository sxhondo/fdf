/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:13:12 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/10 19:13:12 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_background(t_mlx *mlx)
{
	t_point		tmp;
	size_t 		xi;
	size_t 		yi;
	
	yi = 0;
	while (yi < HEIGHT)	
	{
		xi = 0;
		while (xi < WIDTH)
		{
			tmp.x = xi;
			tmp.y = yi;
			put_pixel(mlx, tmp, 0x121212);
			xi++;
		}
		yi++;
	}
}

void 			isometry(int *x, int *y, int z)
{
	int 		yCart;
	int 		xCart;

	*y *= -1;
	xCart = (*x - *y) * cos(0.523599);
	*x = xCart;

	yCart = *y + (*x + z) * sin(0.523599);
	*y = -yCart;
}

static t_point	change_projection(t_view *v, t_point p)
{
	if (v->mode & M_DEFAULT)
	{
		rotation(v, &p.x, &p.y, &p.z);
		isometry(&p.x, &p.y, p.z);
	}
	else if (v->mode & M_ISO)
	{
		rotation(v, &p.x, &p.y, &p.z);
	}
	return (p);
}

static int 		change_color(t_view *v, t_point p)
{
	int 		color = 0;

	if (v->color == C_DEFAULT)
		color = p.z == 0 ? DEF_TOP_COL : DEF_BOT_COL;
	else if (v->color == C_RETRO)
		color = p.z == 0 ? RET_TOP_COL : RET_BOT_COL;
	else if (v->color == C_PASTEL)
		color = p.z == 0 ? PAS_TOP_COL : PAS_BOT_COL;
	return (color);
}

t_point			create_point(t_view *v, t_map *map, size_t x, size_t y)
{
	size_t 		*m;
	t_point		p;

	m = map->vec->data;
	p.x = (x - map->width / 2) * v->zoom;
	p.y = (y - map->height / 2) * v->zoom;	
	p.z = m[x + (y * map->width)] * v->zoom;
	p.color = change_color(v, p);
	p = change_projection(v, p);
	p.x += X_ORIGIN + v->move.x;
	p.y += Y_ORIGIN + v->move.y;
	return (p);
}

t_point 		*project_map(t_map *map, t_view *view)
{
	size_t 		yi;
	size_t 		xi;
	size_t 		i;
	t_point		*p;
	
	if (!(p = (t_point *)malloc(sizeof(t_point) * map->size)))
		display_error(ERR_MEM);
	i = 0;
	yi = 0;
	while (yi < map->height)
	{
		xi = 0;
		while (xi < map->width)
		{
			p[i++] = create_point(view, map, xi, yi);
			xi++;
		}
		yi++;
	}
	return (p);
}

void			drawing(t_map *map, t_view *view, t_mlx *mlx)
{
	size_t		i;
	t_point		*proj;

	i = 0;
	draw_background(mlx);
	proj = project_map(map, view);
	while (i < map->size)
	{
		if (i + map->width < map->size)
			draw_line(proj[i], proj[i + map->width], mlx);
		if ((i + 1) < map->size && (i + 1) % map->width)
			draw_line(proj[i], proj[i + 1], mlx);
		i++;
	}
	free(proj);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
}