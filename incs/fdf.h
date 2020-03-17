/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 19:42:26 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/16 19:42:26 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "mlx.h"
# include "math.h"

# define WIDTH			1024
# define HEIGHT			768

# define WIN_WIDTH		WIDTH + 200
# define WIN_HEIGHT		HEIGHT

# define X_ORIGIN 		(WIDTH / 2)
# define Y_ORIGIN 		(HEIGHT / 2 + 100)

# define C_DEFAULT		1u
# define C_RETRO 		2u
# define C_PASTEL		3u

# define DEF_TOP_COL	0x3A44B0
# define DEF_BOT_COL	0xE01990
# define RET_TOP_COL	0x1FD0E2
# define RET_BOT_COL	0xFF00FF
# define PAS_TOP_COL	0x976EFF
# define PAS_BOT_COL	0xADFFB8
# define C_MENU			0xAFAFAF

# define M_DEFAULT		1u
# define M_ISO			2u

# define ERR_MEM		"allocation failures"
# define ERR_READ		"error while opening file"
# define ERR_MAP		"invalid map"

typedef struct			s_map
{
	t_vec				*vec;
	size_t				height;
	size_t				width;
	size_t				size;
}						t_map;

typedef struct			s_point
{
	int					x;
	int					y;
	int					z;
	unsigned			color;
}						t_point;

typedef struct			s_view
{
	double				x_alpha;
	double				y_alpha;
	double				z_alpha;
	int					zoom;
	unsigned			mode;
	unsigned			color;
	struct s_point		move;
}						t_view;

typedef struct			s_mlx
{
	void				*mlx;
	void				*window;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_mlx;

typedef struct			s_fdf
{
	struct s_mlx		*mlx;
	struct s_map		*map;
	struct s_view		*view;
}						t_fdf;

/*
**	utilities.c
*/
void					display_error(char *text);
size_t					fdf_atoi(const char *str, size_t *color);

/*
**	init.c
*/
t_view					*init_view(t_map *map);
t_mlx					*init_mlx();
t_map					*init_map();

/*
**	read_file.c
*/
t_map					*read_map(char *path);

/*
**	key_handler.c
*/
void					key_hook(t_fdf fdf);

/*
**	drawing.c
*/
void					drawing(t_map *map, t_view *v, t_mlx *mlx);

/*
**	draw_line.c
*/
void					put_pixel(t_mlx *mlx, t_point p, unsigned color);
void					draw_line(t_point src, t_point dst, t_mlx *mlx);

/*
**	draw_window.c
*/
void					draw_background(t_mlx *mlx, t_view *view);

/*
**	rotation_matrix.c
*/
void					rotation(t_view *v, int *x, int *y, int *z);

/*
**	projection.c
*/
t_point					*project_map(t_map *map, t_view *view);

/*
**	color.c
*/
int						get_gradient(t_point cur, t_point src, t_point dst,
															int sign);
#endif
