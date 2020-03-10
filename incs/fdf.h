#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"
#include "math.h"

# define WIDTH		800
# define HEIGHT		600

# define X_ORIGIN 	WIDTH / 5
# define Y_ORIGIN 	HEIGHT - 100

# define ERR_MEM	"allocation failures"
# define ERR_READ	"error while opening file"

typedef struct	s_map
{
	t_vec 		*vec;
	size_t 		height;
	size_t		width;
	size_t 		size; 
}				t_map;

typedef struct 	s_point
{
	int			x;
	int			y;
	size_t 		z;
}				t_point;

typedef struct	s_view
{
	float 		x_rot[3][3];
	// int			y_rot[3][3];
	// int 		z_rot[3][3];
	int 		x_r;
	// int 		y_r;
	// int 		z_r;
	int 		zoom;
}				t_view;

typedef struct 	s_mlx
{
	void 			*mlx;
	void 			*window;
	void 			*img;
	char			*data_addr;
	int 			bits_per_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct 		s_fdf
{
	struct s_mlx	*mlx;
	struct s_map	*map;
	struct s_view	*view;
}					t_fdf;

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
**	key_handler.c
*/
void			key_hook(t_fdf *fdf);

/*
**	drawing.c
*/
void			drawing(t_map *map, t_view *v, t_mlx *mlx);

/*
**	draw_line.c
*/
void			put_pixel(t_mlx *mlx, t_point p, unsigned color);
void			draw_line(t_point src, t_point dst, t_mlx *mlx);

/*
**	rotation_matrix.c
*/
void 			x_rotation(int alpha, float x_rot[3][3]);
// void			y_rotation(int alpha, int y_rot[3][3]);
// void			z_rotation(int alpha, int z_rot[3][3]);
void 			apply_rotation(t_view *v, int *x, int *y, int *z);

# endif