/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_mac_os.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:13:24 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/20 14:10:45 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

static void		exit_free(t_mlx *mlx, t_view *view, t_map *map)
{
	ft_vec_del(&(map->vec));
	free(map);
	free(view);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx_destroy_window(mlx->mlx, mlx->window);
	free(mlx);
	exit(0);
}

static void		arrows_zoom_handler(int keycode, t_view *view)
{
	if (keycode == MO_PLUS || keycode == MO_MINUS)
	{
		view->zoom += keycode == MO_PLUS ? 1 : -1;
		if (view->zoom <= 0)
			view->zoom = 1;
	}
	if (keycode == MO_ARR_LEFT)
		view->move.x -= WIDTH / 100;
	else if (keycode == MO_ARR_RIGHT)
		view->move.x += WIDTH / 100;
	else if (keycode == MO_ARR_DOWN)
		view->move.y += HEIGHT / 100;
	else if (keycode == MO_ARR_UP)
		view->move.y -= HEIGHT / 100;
}

static void		rot_projection_handler(int keycode, t_view *view)
{
	if (keycode == MO_S || keycode == MO_W)
		view->x_alpha += keycode == MO_S ? 0.1 : -0.1;
	else if (keycode == MO_A || keycode == MO_D)
		view->y_alpha += keycode == MO_A ? 0.1 : -0.1;
	else if (keycode == MO_E || keycode == MO_Q)
		view->z_alpha += keycode == MO_Q ? 0.1 : -0.1;
	if (keycode == MO_Z)
	{
		view->x_alpha = 0;
		view->y_alpha = 0;
		view->z_alpha = 0;
		if (++(view->mode) > M_ISO)
			view->mode = M_DEFAULT;
	}
}

static int		key_handler(int keycode, t_fdf *f)
{
	if (keycode == MO_ESC || keycode == MO_X)
		exit_free(f->mlx, f->view, f->map);
	else if (keycode == MO_S || keycode == MO_W
	|| keycode == MO_A || keycode == MO_D ||
	keycode == MO_E || keycode == MO_Q || keycode == MO_Z)
		rot_projection_handler(keycode, f->view);
	else if (keycode == MO_ARR_LEFT || keycode == MO_ARR_RIGHT
	|| keycode == MO_ARR_UP || keycode == MO_ARR_DOWN ||
	keycode == MO_PLUS || keycode == MO_MINUS)
		arrows_zoom_handler(keycode, f->view);
	else if (keycode == MO_C)
		if (++(f->view->color) > C_PASTEL)
			f->view->color = C_DEFAULT;
	drawing(f->map, f->view, f->mlx);
	return (0);
}

void			key_hook(t_fdf *fdf)
{
	mlx_hook(fdf.mlx->window, 2, 0, key_handler, fdf);
}
