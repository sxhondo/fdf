/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:13:24 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/20 14:22:03 by sxhondo          ###   ########.fr       */
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
	if (keycode == LIN_PLUS || keycode == LIN_MINUS)
	{
		view->zoom += keycode == LIN_PLUS ? 1 : -1;
		if (view->zoom <= 0)
			view->zoom = 1;
	}
	if (keycode == LIN_ARR_LEFT)
		view->move.x -= WIDTH / 100;
	else if (keycode == LIN_ARR_RIGHT)
		view->move.x += WIDTH / 100;
	else if (keycode == LIN_ARR_DOWN)
		view->move.y += HEIGHT / 100;
	else if (keycode == LIN_ARR_UP)
		view->move.y -= HEIGHT / 100;
}

static void		rot_projection_handler(int keycode, t_view *view)
{
	if (keycode == LIN_S || keycode == LIN_W)
		view->x_alpha += keycode == LIN_S ? 0.1 : -0.1;
	else if (keycode == LIN_A || keycode == LIN_D)
		view->y_alpha += keycode == LIN_A ? 0.1 : -0.1;
	else if (keycode == LIN_E || keycode == LIN_Q)
		view->z_alpha += keycode == LIN_Q ? 0.1 : -0.1;
	if (keycode == LIN_Z)
	{
		view->x_alpha = 0;
		view->y_alpha = 0;
		view->z_alpha = 0;
		if (++(view->mode) > M_ISO)
			view->mode = M_DEFAULT;
	}
}

static int		key_press(int keycode, t_fdf *f)
{
	if (keycode == LIN_X || keycode == LIN_ESC)
		exit_free(f->mlx, f->view, f->map);		
	if (keycode == LIN_ARR_LEFT || keycode == LIN_ARR_RIGHT
		|| keycode == LIN_ARR_UP || keycode == LIN_ARR_DOWN ||
		keycode == LIN_PLUS || keycode == LIN_MINUS)
		arrows_zoom_handler(keycode, f->view);
	if (keycode == LIN_S || keycode == LIN_W
	|| keycode == LIN_A || keycode == LIN_D ||
	keycode == LIN_E || keycode == LIN_Q || keycode == LIN_Z)
		rot_projection_handler(keycode, f->view);
	if (keycode == LIN_C)
		if (++(f->view->color) > C_PASTEL)
			f->view->color = C_DEFAULT;
	drawing(f->map, f->view, f->mlx);
	return (0);
}

void			key_hook(t_fdf *fdf)
{
	mlx_hook(fdf->mlx->window, 2, (1L << 0), key_press, fdf);
}
