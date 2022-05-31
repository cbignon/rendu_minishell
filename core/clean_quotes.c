/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:28:01 by atron             #+#    #+#             */
/*   Updated: 2022/04/20 11:01:49 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

void	clean_args_quotes(char **args)
{
	int	index;

	index = 0;
	while (args[index])
	{
		skip_quotes(args[index], 0);
		index++;
	}
}

void	clean_quotes(t_process *processes)
{
	int	index;

	index = 0;
	while (processes[index].val)
	{
		skip_quotes(processes[index].cmd, 0);
		if (!ft_str_equ(processes[index].cmd, "export"))
			clean_args_quotes(processes[index].args);
		index++;
	}
}
