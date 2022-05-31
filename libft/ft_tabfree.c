/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:56:20 by atron             #+#    #+#             */
/*   Updated: 2021/06/09 15:42:40 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tabfree(void ***tab, int size, int out)
{
	int	x;

	x = 0;
	if (*tab)
	{
		while (x < size)
		{
			ft_free(&(*tab)[x], 0);
			x++;
		}
		ft_free((void **)tab, 0);
	}
	return (out);
}

int	ft_tabfree_cu(void ***tab, int size, int out)
{
	int	x;

	x = 0;
	if (*tab)
	{
		while (x < size)
		{
			gc_delone(&(*tab)[x], 0);
			x++;
		}
		gc_delone((void **)tab, 0);
	}
	return (out);
}
