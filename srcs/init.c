/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:13:31 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/10 19:13:32 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_view			*init_view(t_map *map)
{
	t_view		*v;

	if (!(v = ft_memalloc(sizeof(t_view))))
		display_error("ERR_MEM");
	v->zoom = (WIDTH / map->width / 2);
	v->x_alpha = 0.0;
	v->y_alpha = 0.0;
	v->z_alpha = 0.0;
	v->mode = M_DEFAULT;
	v->color = C_DEFAULT;
	v->move.x = 0;
	v->move.y = 0;
	return (v);
}

t_mlx			*init_mlx(void)
{
	t_mlx		*p;

	if (!(p = ft_memalloc(sizeof(t_mlx))))
		display_error(ERR_MEM);
	if (!(p->mlx = mlx_init()))
		display_error(ERR_MEM);
	if (!(p->window = mlx_new_window(p->mlx, WIN_WIDTH, WIN_HEIGHT, "FdF")))
		display_error(ERR_MEM);
	if (!(p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT)))
		display_error(ERR_MEM);
	if (!(p->data_addr = mlx_get_data_addr(p->img,
		&(p->bits_per_pixel), &(p->size_line), &(p->endian))))
		display_error(ERR_MEM);
	return (p);
}

t_map			*init_map(void)
{
	t_map		*m;

	if (!(m = ft_memalloc(sizeof(t_map))))
		display_error("ERR_MEM");
	m->width = 0;
	m->height = 0;
	return (m);
}
