/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:07:50 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/27 14:06:10 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	close_fd(t_process *p)
{
	int			i;
	t_process	*proc_list;

	i = 0;
	proc_list = p - p->proc_index;
	while (i < proc_list->proc_count - 1)
	{
		if (proc_list[i].proc_index == i)
		{
			close(proc_list[i].pipe_out[1]);
			if (proc_list[i].proc_index > 0)
			{
				close(proc_list[i].pipe_in[0]);
				close(proc_list[i].pipe_out[1]);
			}
		}
		else if (proc_list[i].proc_index > 0)
			close(proc_list[i].pipe_in[1]);
		i++;
	}
	return (0);
}

void	close_one_proc_fd(t_process *p)
{
	if (p->proc_index > 0)
	{
		close(p->pipe_in[0]);
		close(p->pipe_in[1]);
	}
	if (p->proc_index < p->proc_count - 1)
	{
		close(p->pipe_out[0]);
		close(p->pipe_out[1]);
	}
}
