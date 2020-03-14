/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:13:25 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/10 19:23:51 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void 			draw_menu(t_mlx *mlx, t_view *view)
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
		WIN_WIDTH - 185, 155, C_MENU, "  Z    projection");
	mlx_string_put(mlx->mlx, mlx->window, 
		WIN_WIDTH - 185, 185, C_MENU, "  C    color");
	mlx_string_put(mlx->mlx, mlx->window, 
		WIN_WIDTH - 185, 215, C_MENU, " -/+   zoom");
	mlx_string_put(mlx->mlx, mlx->window, 
		WIN_WIDTH - 185, WIN_HEIGHT - 50, C_MENU, "  X/ESC   exit");
}

int				main(int ac, char **av)
{
	t_fdf		f;	

	if (ac == 2)
	{
		f.map = read_map(av[1]);
		f.mlx = init_mlx();
		f.view = init_view(f.map);
		key_hook(f);
		drawing(f.map, f.view, f.mlx);
		draw_menu(f.mlx, f.view);
		mlx_loop(f.mlx->mlx);
		ft_vec_del(&f.map->vec);
	}
  	return (0);
}
