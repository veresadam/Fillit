/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psular <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:49:19 by psular            #+#    #+#             */
/*   Updated: 2017/12/19 17:08:49 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int x;
	int y;
}				t_point;

typedef	struct	s_piece
{
	t_point		pieces[4];
	char		value;
}				t_piece;

typedef struct	s_map
{
	char		**map;
	int			size;
}				t_map;

int				file_exist(char *name);
int				connections(char *piece);
int				count_connections(char *piece, int i, int j);
int				file_max(char *name);
t_list			*ft_read(char *name);
t_list			*piece_letter(t_list *tetris_piece);
t_piece			*string_piece(char *piece);
void			piece_top_left(t_piece **tetris_piece);
int				read_piece(int fd, char **piece);
int				valid_piece(char *piece, int t_len);
void			free_tetrimino(void *tetrimino, size_t size);
void			free_list(t_list **tetriminos);
t_map			*make_map(int size);
t_map			*cpy_map(t_map *og_map);
void			del_map(t_map **map);
void			print_map(t_map *map_ptr);
int				try_place(t_map **map, int i, int j, t_piece *tetrimino);
int				fill_map(t_list *tetriminos, t_map **map, int size);
t_map			*solve(t_list *tetriminos);
#endif
