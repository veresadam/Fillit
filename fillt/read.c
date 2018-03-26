/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adveres <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 13:44:59 by adveres           #+#    #+#             */
/*   Updated: 2017/12/19 17:05:10 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		file_exist(char *name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int		count_connections(char *piece, int i, int j)
{
	int count;

	count = 0;
	if (i > 0 && piece[(i - 1) * 5 + j] == '#')
		count++;
	if (i < 3 && piece[(i + 1) * 5 + j] == '#')
		count++;
	if (j > 0 && piece[i * 5 + (j - 1)] == '#')
		count++;
	if (j < 3 && piece[i * 5 + (j + 1)] == '#')
		count++;
	return (count);
}

int		connections(char *piece)
{
	int	i;
	int	j;
	int con;

	con = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (piece[i * 5 + j] == '#')
				con += count_connections(piece, i, j);
			j++;
		}
		i++;
	}
	if (con >= 6)
		return (1);
	return (0);
}

int		file_max(char *name)
{
	int		fd;
	int		nr;
	char	*buf;

	buf = (char*)malloc((545 + 1) * sizeof(char));
	if (buf == NULL)
		return (0);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (0);
	nr = read(fd, buf, 545 + 1);
	free(buf);
	close(fd);
	return (nr > 545);
}

t_list	*ft_read(char *name)
{
	t_list	*tetris_piece;
	int		fd;
	char	*piece;
	int		nr;

	tetris_piece = NULL;
	if (file_exist(name) && !file_max(name))
	{
		fd = open(name, O_RDONLY);
		if (fd == -1)
			return (NULL);
		while ((nr = read_piece(fd, &piece)) == 1)
			ft_lstlast(&tetris_piece, ft_lstnew(string_piece(piece),
						sizeof(t_piece)));
		if (nr == -1)
		{
			free_list(&tetris_piece);
			return (NULL);
		}
		ft_lstlast(&tetris_piece, ft_lstnew(string_piece(piece),
					sizeof(t_piece)));
		close(fd);
		return (piece_letter(tetris_piece));
	}
	return (NULL);
}
