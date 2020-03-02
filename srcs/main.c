#include "fdf.h"

int 			main(int ac, char **av)
{
	void 		*mlx;
  	void		*window;
  
	mlx = mlx_init();
  	
	window = mlx_new_window(mlx, 1000, 1000, "Title");

  	mlx_loop(mlx);
  	return (0);
}