/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sxhondo <w13cho@gmail.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 20:50:52 by sxhondo           #+#    #+#             */
/*   Updated: 2020/03/02 20:50:53 by sxhondo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char **open_file(char *path)
{
	char 	**split;
	t_vec	*file;
	int 	fd;

	if ((fd = open(path, O_RDONLY)) == -1)
		display_error(ERR_READ);
	if (!(file = ft_vec_read(fd)))
		display_error(ERR_MEM);
	if (!(split = ft_strsplit(file->data, '\n')))
		display_error(ERR_MEM);
	ft_vec_del(&file);
	close(fd);
	return (split);
}

static void 		parse_line(t_vec **vec, char *line, int *map_width)
{
	size_t 			i;
	int32_t			val;
	char 			**ln;

	i = -1;
	if (!(ln = ft_strsplit(line, ' ')))
		display_error(ERR_MEM);
	while (ln[++i])
	{
		if (!(atoi_base(ln[i], &val)))
			;
		ft_vec_add(vec, &val);
	}
	*map_width = i;
	ft_strsplit_free(ln);
}

t_map			*read_map(char *path)
{
	size_t 		i;
	t_vec		*vec;
	char 		**file;
	t_map		*map;
	
	i = -1;
	map = init_map();	
	file = open_file(path);
	if (!(vec = ft_vec_init(1, sizeof(size_t))))
		display_error(ERR_MEM);
	while (file[++i])
	{
		parse_line(&vec, file[i], &map->width);
		map->height += 1;
	}
	if (!(ft_vec_resize(&vec)))
	{
		ft_vec_del(&vec);
		display_error(ERR_MEM);
	}
	map->vec = vec;
	map->size = vec->total;
	ft_strsplit_free(file);
	return (map);
}
