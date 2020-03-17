/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 17:32:33 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/16 17:32:34 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_menu_options(t_mlx *mlx, t_view *view)
{
	if (view->mode == M_ISO)
		mlx_string_put(mlx->mlx, mlx->window,
			WIN_WIDTH - 185, 155, C_MENU, "  Z    [parallel]");
	else if (view->mode == M_DEFAULT)
		mlx_string_put(mlx->mlx, mlx->window,
			WIN_WIDTH - 185, 155, C_MENU, "  Z    [isometry]");
	if (view->color == C_DEFAULT)
		mlx_string_put(mlx->mlx, mlx->window,
			WIN_WIDTH - 185, 185, C_MENU, "  C    [default]");
	else if (view->color == C_RETRO)
		mlx_string_put(mlx->mlx, mlx->window,
			WIN_WIDTH - 185, 185, C_MENU, "  C    [retro]");
	else if (view->color == C_PASTEL)
		mlx_string_put(mlx->mlx, mlx->window,
			WIN_WIDTH - 185, 185, C_MENU, "  C    [pastel]");
}

static void		draw_menu(t_mlx *mlx, t_view *view)
{
	mlx_string_put(mlx->mlx, mlx->window,
		WIN_WIDTH - 145, 0, C_MENU, "controls:");
	mlx_string_put(mlx->mlx, mlx->window,
		WIN_WIDTH - 185, 35, C_MENU, "W - S  x rotation");
	mlx_string_put(mlx->mlx, mlx->window,
		WIN_WIDTH - 185, 55, C_MENU, "A - D  y rotation");
	mlx_string_put(mlx->mlx, mlx->window,
		WIN_WIDTH - 185, 75, C_MENU, "Q - E  z rotation");
	mlx_string_put(mlx->mlx, mlx->window,
		WIN_WIDTH - 185, 115, C_MENU, "ARROWS move");
	mlx_string_put(mlx->mlx, mlx->window,
		WIN_WIDTH - 185, 215, C_MENU, " -/+   zoom");
	mlx_string_put(mlx->mlx, mlx->window,
		WIN_WIDTH - 185, WIN_HEIGHT - 50, C_MENU, "  X/ESC   exit");
	draw_menu_options(mlx, view);
}

void			draw_background(t_mlx *mlx, t_view *view)
{
	t_point		tmp;
	size_t		xi;
	size_t		yi;

	mlx_clear_window(mlx->mlx, mlx->window);
	draw_menu(mlx, view);
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
