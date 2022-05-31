/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:56:54 by atron             #+#    #+#             */
/*   Updated: 2022/04/22 16:05:37 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool	in_index(int *lst, int value)
{
	int	index;

	index = 0;
	if (!lst)
		return (FALSE);
	while (lst[index] > -1)
	{
		if (lst[index] == value)
			return (TRUE);
		index++;
	}
	return (FALSE);
}

int	*append_index(int *lst, int elem)
{
	int	index;
	int	*out;
	int	size;

	index = 0;
	size = 0;
	if (!lst)
	{
		out = (int *)malloc_verify(sizeof(int) * 2);
		out[0] = elem;
		out[1] = -1;
		return (out);
	}
	while (lst[size] > -1)
		size++;
	out = (int *)malloc_verify(sizeof(int) * (size + 2));
	while (index < size)
	{
		out[index] = lst[index];
		index++;
	}
	out[index++] = elem;
	out[index] = -1;
	gc_delone((void **)&lst, 0);
	return (out);
}
