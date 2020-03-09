/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 13:52:42 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/04 13:52:43 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 			isometry(int *x, int *y, int z)
{
	int 		yCart;
	int 		xCart;

	*y *= -1;
	xCart = (*x - *y) * cos(0.46365);
	*x = xCart + X_ORIGIN;

	yCart = *y + (*x + z) * sin(0.46365);
	*y = -yCart + Y_ORIGIN;
}

t_point 		create_point(t_view *v, t_map *map, size_t x, size_t y)
{
	size_t 		*m;
	t_point		p;

	m = map->vec->data;

	p.x = (x * v->zoom);
	p.y = (y * v->zoom);
	p.z = m[x + (y * map->width)];
	isometry(&p.x, &p.y, p.z);
	return (p);
}

t_point 		*project_map(t_map *map, t_view *view, t_mlx *mlx)
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
	size_t 		i;
	t_point		*proj;
	
	i = 0;
	proj = project_map(map, view, mlx);
	while (i < map->size)
	{
		if (i + map->width < map->size)
			draw_line(proj[i], proj[i + map->width], mlx);
		if (i + 1 < map->size && (i + 1) % map->width)
			draw_line(proj[i], proj[i + 1], mlx);
		i++;
	}
	free(proj);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->img, 0, 0);
	mlx_loop(mlx->mlx);
}









