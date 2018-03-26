/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psular <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:27:45 by psular            #+#    #+#             */
/*   Updated: 2017/12/19 16:53:23 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_place(t_map **map, int i, int j, t_piece *tetrimino)
{
	int index;
	int	ok;

	index = 0;
	ok = 1;
	while (index < 4 && ok)
	{
		if (i + tetrimino->pieces[index].x >= (*map)->size ||
			j + tetrimino->pieces[index].y >= (*map)->size ||
			((*map)->map[i + tetrimino->pieces[index].x][j +
			tetrimino->pieces[index].y] != '.'))
			ok = 0;
		index++;
	}
	if (ok)
	{
		index = -1;
		while (++index < 4)
			(*map)->map[i + tetrimino->pieces[index].x][j +
			tetrimino->pieces[index].y] = tetrimino->value;
		return (1);
	}
	return (0);
}

int		fill_map(t_list *tetriminos, t_map **map, int size)
{
	int		i;
	int		j;
	t_map	*map_cpy;

	if (tetriminos == NULL)
		return (1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			map_cpy = cpy_map(*map);
			if (try_place(map, i, j, (t_piece*)(tetriminos->content)))
				if (fill_map(tetriminos->next, map, size))
				{
					del_map(&map_cpy);
					return (1);
				}
			del_map(map);
			*map = map_cpy;
		}
	}
	return (0);
}

t_map	*solve(t_list *tetriminos)
{
	int		size;
	t_map	*map;

	size = 2;
	map = make_map(size);
	if (map == NULL)
		return (NULL);
	while (!fill_map(tetriminos, &map, size))
	{
		del_map(&map);
		map = make_map(++size);
		if (map == NULL)
			return (NULL);
	}
	return (map);
}

void	print_map(t_map *map_ptr)
{
	int i;
	int j;

	i = 0;
	while (i < map_ptr->size)
	{
		j = 0;
		while (j < map_ptr->size)
			ft_putchar(map_ptr->map[i][j++]);
		ft_putchar('\n');
		i++;
	}
}
