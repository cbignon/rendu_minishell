/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:14:54 by atron             #+#    #+#             */
/*   Updated: 2022/04/28 11:15:06 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split_internal.h"

static t_arg_info	*append_arg_info(t_arg_info **args_info, int *i, char *str)
{
	int			in_size;
	int			length;
	t_arg_info	*tmp;
	t_arg_info	arg;

	length = 0;
	in_size = get_arg_count(*args_info);
	tmp = realloc_arg_info(*args_info, in_size + 1);
	if (!tmp)
		return (NULL);
	arg.start = &str[*i];
	length = get_arg_length(&str[*i], 0);
	arg.length = length;
	tmp[in_size] = arg;
	*i = *i + length;
	*args_info = tmp;
	return (tmp);
}

t_arg_info	*get_args_info(char *str)
{
	int			i;
	t_arg_info	*args_info;

	i = 0;
	args_info = NULL;
	if (!str || !str[0])
		return (NULL);
	while (str[i])
	{
		i = pass_white_space(i, str);
		if (str[i])
			args_info = append_arg_info(&args_info, &i, str);
	}
	return (args_info);
}
