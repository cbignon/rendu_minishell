/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 10:44:35 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/20 11:09:25 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	pipe_proc(t_process *processes, int index)
{
	int	pipe_fd[2];

	pipe_fd[0] = 0;
	pipe_fd[1] = 1;
	if (pipe(pipe_fd) == -1)
		return (-1);
	processes[index].pipe_out[0] = pipe_fd[0];
	processes[index].pipe_out[1] = pipe_fd[1];
	processes[index + 1].pipe_in[0] = pipe_fd[0];
	processes[index + 1].pipe_in[1] = pipe_fd[1];
	return (0);
}

int	create_pipe(t_process *processes)
{
	int	i;

	i = 0;
	while (processes[i + 1].val)
	{
		if (pipe_proc(processes, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}
