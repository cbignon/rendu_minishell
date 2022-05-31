/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:11:42 by atron             #+#    #+#             */
/*   Updated: 2022/04/22 16:05:38 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split_internal.h"

t_arg_info	*calloc_arg_info(int size)
{
	int			index;
	t_arg_info	*ptr;

	index = 0;
	ptr = (t_arg_info *)malloc_verify(sizeof(t_arg_info) * size);
	if (!ptr)
		return (NULL);
	while (index < size)
	{
		ptr[index].length = -1;
		ptr[index].start = NULL;
		index++;
	}
	return (ptr);
}

t_arg_info	*realloc_arg_info(t_arg_info *args_info, int out_size)
{
	t_arg_info	*tmp;
	int			size;

	if (!args_info)
	{
		args_info = calloc_arg_info(out_size + 1);
		return (args_info);
	}
	tmp = calloc_arg_info(out_size + 1);
	if (!tmp)
		return (NULL);
	size = get_arg_count(args_info);
	ft_memmove(tmp, args_info, size * sizeof(t_arg_info));
	gc_delone((void **)&args_info, 0);
	return (tmp);
}
