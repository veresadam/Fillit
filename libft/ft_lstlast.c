/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psular <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 17:32:03 by psular            #+#    #+#             */
/*   Updated: 2017/12/17 19:53:13 by psular           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstlast(t_list **alst, t_list *last)
{
	t_list	*list;

	if (alst != NULL)
	{
		if (*alst == NULL)
			*alst = last;
		else
		{
			list = *alst;
			while (list->next != NULL)
				list = list->next;
			list->next = last;
		}
	}
}
