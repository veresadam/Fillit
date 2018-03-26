/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psular <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:59:37 by psular            #+#    #+#             */
/*   Updated: 2017/12/19 16:54:38 by adveres          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list		*piece_letter(t_list *tetris_piece)
{
	t_list	*list;
	char	letter;

	letter = 'A';
	list = tetris_piece;
	while (list)
	{
		((t_piece*)(list->content))->value = letter;
		letter++;
		list = list->next;
	}
	return (tetris_piece);
}

t_piece		*string_piece(char *piece)
{
	t_piece	*tetris_piece;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tetris_piece = (t_piece*)malloc(sizeof(t_piece));
	if (tetris_piece == NULL)
		return (NULL);
	while (i < 20)
	{
		if (piece[i] == '#')
		{
			tetris_piece->pieces[j].x = i / 5;
			tetris_piece->pieces[j++].y = i % 5;
		}
		i++;
	}
	piece_top_left(&tetris_piece);
	return (tetris_piece);
}

void		piece_top_left(t_piece **tetris_piece)
{
	int	top;
	int	left;
	int	i;

	top = 4;
	left = 4;
	i = 0;
	while (i < 4)
	{
		if ((*tetris_piece)->pieces[i].x < top)
			top = (*tetris_piece)->pieces[i].x;
		if ((*tetris_piece)->pieces[i].y < left)
			left = (*tetris_piece)->pieces[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		(*tetris_piece)->pieces[i].x -= top;
		(*tetris_piece)->pieces[i++].y -= left;
	}
}

int			read_piece(int fd, char **piece)
{
	int		nr;
	char	c;

	*piece = ft_strnew(20);
	if (piece == NULL)
		return (-1);
	nr = read(fd, *piece, 20);
	if (!valid_piece(*piece, 20))
	{
		ft_strdel(piece);
		return (-1);
	}
	if (nr != 20)
	{
		ft_strdel(piece);
		return (-1);
	}
	nr = read(fd, &c, 1);
	if (nr == 0)
		return (0);
	else if (c == '\n')
		return (1);
	return (-1);
}

int			valid_piece(char *piece, int t_len)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if ((int)ft_strlen(piece) != t_len)
		return (0);
	if (piece[4] != '\n' || piece[9] != '\n'
			|| piece[14] != '\n' || piece[19] != '\n')
		return (0);
	while (i < t_len)
	{
		if (piece[i] == '#')
			count++;
		else if (piece[i] != '.' && piece[i] != '\n')
			return (0);
		i++;
	}
	if (count != 4)
		return (0);
	return (connections(piece));
}
