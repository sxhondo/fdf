/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 18:38:07 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/10 19:14:58 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					put_pixel(t_mlx *mlx, t_point p, unsigned color)
{
	size_t				i;

	if (p.x >= WIDTH || p.y >= HEIGHT || p.y < 0 || p.x < 0)
		return ;
	i = (p.x * mlx->bits_per_pixel / 8) + (p.y * mlx->size_line);
	if (mlx->endian == 0)
	{
		mlx->data_addr[i] = (char)color;
		mlx->data_addr[++i] = (char)(color >> 8u);
		mlx->data_addr[++i] = (char)(color >> 16u);
	}
	else if (mlx->endian == 1)
	{
		mlx->data_addr[i] = (char)(color >> 16u);
		mlx->data_addr[++i] = (char)(color >> 8u);
		mlx->data_addr[++i] = (char)(color);
	}
}

static void				up_angle(t_mlx *mlx, t_point src, t_point dst,
															t_point delta)
{
	t_point				sig;
	t_point				cur;
	int					error;

	error = 0;
	cur = src;
	sig.y = delta.y < 0 ? -1 : 1;
	sig.x = delta.x < 0 ? -1 : 1;
	while (cur.x != dst.x || cur.y != dst.y)
	{
		put_pixel(mlx, cur, get_gradient(cur, src, dst, -1));
		error += delta.y * sig.y;
		if (error > 0)
		{
			error -= delta.x * sig.x;
			cur.y += sig.y;
		}
		cur.x -= sig.x;
	}
}

static void				down_angle(t_mlx *mlx, t_point src, t_point dst,
																t_point delta)
{
	t_point				sig;
	t_point				cur;
	int					error;

	error = 0;
	cur = src;
	sig.y = delta.y < 0 ? -1 : 1;
	sig.x = delta.x < 0 ? -1 : 1;
	while (cur.x != dst.x || cur.y != dst.y)
	{
		put_pixel(mlx, cur, get_gradient(cur, src, dst, 1));
		error += delta.x * sig.x;
		if (error > 0)
		{
			error -= delta.y * sig.y;
			cur.x -= sig.x;
		}
		cur.y += sig.y;
	}
}

void					draw_line(t_point src, t_point dst, t_mlx *mlx)
{
	t_point				delta;
	int					sign;

	delta.y = dst.y - src.y;
	delta.x = src.x - dst.x;
	sign = ft_abs(delta.y) > ft_abs(delta.x) ? 1 : -1;
	if (sign == -1)
		up_angle(mlx, src, dst, delta);
	if (sign == 1)
		down_angle(mlx, src, dst, delta);
}
