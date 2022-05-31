/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:38:40 by atron             #+#    #+#             */
/*   Updated: 2022/04/22 16:05:37 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split_internal.h"

/**
 *  Splits arguments into seperate strings.
 *
 *  @param str   Command to split.
 *  @return      List of arguments.
 */
char	**ft_split_args(char *str)
{
	t_arg_info	*args_info;
	int			index;
	int			size;
	char		**tab;

	if (!str)
		return (NULL);
	index = 0;
	args_info = get_args_info(str);
	size = get_arg_count(args_info);
	tab = (char **)malloc_verify(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	while (index < size)
	{
		tab[index] = ft_strndup_cu(args_info[index].start,
				args_info[index].length);
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
