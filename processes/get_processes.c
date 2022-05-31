/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:44:04 by atron             #+#    #+#             */
/*   Updated: 2022/04/22 16:05:38 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "processes_internal.h"

t_process	**get_processes(int size)
{
	static t_process	*processes;

	if (!processes && size > 0)
		processes = (t_process *)malloc_verify(sizeof(t_process) * (size + 2));
	return (&processes);
}

t_process	*find_process(t_process *p, pid_t pid)
{
	int	index;

	index = 0;
	if (!p)
		return (NULL);
	while (p[index].val)
	{
		if (p[index].pid == pid)
		{
			return (&p[index]);
		}
		index++;
	}
	return (NULL);
}
