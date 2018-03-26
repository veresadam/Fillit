/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:28:22 by adveres           #+#    #+#             */
/*   Updated: 2017/12/19 16:55:11 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	free_tetrimino(void *tetrimino, size_t size)
{
	if (size != 0)
		free(tetrimino);
	tetrimino = NULL;
}

void	free_list(t_list **tetriminos)
{
	if (tetriminos != NULL)
		ft_lstdel(tetriminos, &free_tetrimino);
}

t_map	*make_map(int size)
{
	t_map	*map_ptr;
	int		i;
	int		j;

	map_ptr = (t_map*)malloc(sizeof(t_map));
	if (map_ptr == NULL)
		return (NULL);
	map_ptr->map = (char**)malloc(sizeof(char*) * size);
	if (map_ptr->map == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		map_ptr->map[i] = ft_strnew(size - 1);
		if (map_ptr->map[i] == NULL)
			return (NULL);
		j = 0;
		while (j < size)
			map_ptr->map[i][j++] = '.';
		i++;
	}
	map_ptr->size = size;
	return (map_ptr);
}

t_map	*cpy_map(t_map *og_map)
{
	t_map	*new_map;
	int		i;
	int		j;

	new_map = make_map(og_map->size);
	if (new_map == NULL)
		return (NULL);
	i = 0;
	while (i < og_map->size)
	{
		j = 0;
		while (j < og_map->size)
		{
			new_map->map[i][j] = og_map->map[i][j];
			j++;
		}
		i++;
	}
	return (new_map);
}

void	del_map(t_map **map)
{
	int	i;

	i = 0;
	while (i < (*map)->size)
		ft_memdel((void **)&(*map)->map[i++]);
	ft_memdel((void **)&(*map)->map);
	ft_memdel((void**)&(*map));
}
