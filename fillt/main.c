/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psular <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:58:49 by psular            #+#    #+#             */
/*   Updated: 2017/12/17 17:46:58 by psular           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_list		*tetriminos;
	t_map		*map;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	else
	{
		tetriminos = ft_read(argv[1]);
		if (tetriminos == NULL)
		{
			ft_putstr("error\n");
			return (1);
		}
		else
		{
			map = solve(tetriminos);
			print_map(map);
			del_map(&map);
			free_list(&tetriminos);
		}
	}
	return (0);
}
