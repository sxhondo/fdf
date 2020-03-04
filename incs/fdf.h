#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"

# define WIDTH		800
# define HEIGHT		600

# define ERR_MEM	"allocation failures"
# define ERR_READ	"error while opening file"

typedef struct	s_map
{
	t_vec 		*vec;
	int 		height;
	int 		width;
	size_t 		size; 
}				t_map;

typedef struct 	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_view
{
	int 		zoom;
}				t_view;


typedef struct 	s_mlx
{
	void 		*mlx;
	void 		*window;
	void 		*img;
	char		*data_addr;
	int 		bits_per_pixel;
	int			size_line;
	int			endian;
}				t_mlx;

/*
**	utilities.c
*/
void			display_error(char *text);
int 			atoi_base(const char *str, int32_t *res);

/*
**	init.c
*/
t_view			*init_view(t_map *map);
t_mlx			*init_mlx();
t_map			*init_map();

/*
**	read_file.c
*/
t_map			*read_map(char *path);

/*
**	drawing.c
*/
void			drawing(t_map *map, t_view *v, t_mlx *mlx);

/*
**	draw_line.c
*/
void			draw_line(t_point src, t_point dst, t_mlx *mlx);

# endif