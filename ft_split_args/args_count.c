/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 11:20:01 by atron             #+#    #+#             */
/*   Updated: 2022/03/09 16:48:38 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_split_internal.h"

int	get_arg_count(t_arg_info	*args_info)
{
	int	index;

	index = 0;
	if (!args_info)
		return (0);
	while (args_info[index].length > 0)
		index++;
	return (index);
}
