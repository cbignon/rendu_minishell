/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:37:58 by cbignon           #+#    #+#             */
/*   Updated: 2022/05/09 17:20:18 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes_internal.h"

t_bool	is_redir(char *arg)
{
	int	index;

	index = ft_strlen(arg) - 1;
	if (is_meta(arg[index]))
		return (TRUE);
	return (FALSE);
}

int	arg_count_no_redir(char **args)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (args[index])
	{
		if (!is_redir(args[index]))
			count++;
		index++;
	}
	return (count);
}

char	**get_real_args(char **args)
{
	int		size;
	char	**out;
	int		index_1;
	int		index_2;

	index_1 = 0;
	index_2 = 0;
	size = arg_count_no_redir(args);
	out = (char **)malloc_verify(sizeof(char *) * (size + 1));
	while (index_1 < size && args[index_2])
	{
		if (is_redir(args[index_2]))
		{
			index_2 += 2;
			continue ;
		}
		out[index_1] = args[index_2];
		if (args[index_2])
			index_2++;
		index_1++;
	}
	out[index_1] = NULL;
	return (out);
}

int	get_redir_count(char **args)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (args[index])
	{
		if (is_redir(args[index]))
			count++;
		index++;
	}
	return (count);
}

int	get_trailing_count(char *str)
{
	int		index;
	char	c;
	int		count;

	count = 0;
	index = ft_strlen(str) - 1;
	c = str[index];
	while (index >= 0 && str[index] == c)
	{
		index--;
		count++;
	}
	return (count);
}
