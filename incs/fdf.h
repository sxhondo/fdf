#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "ft_printf.h"
#include "mlx.h"

typedef struct	s_map
{
	int 		**grid;
	int 		height;
	int 		width;
	size_t 		size;
}				t_map;

/*
**	error.c
*/
void 			display_error(char *text);

/*
**	init.c
*/
t_map			*init_map();

/*
**	read_file.c
*/
t_map			*read_map(char *path);
# endif