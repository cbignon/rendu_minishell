/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 12:07:50 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/13 11:20:22 by Darkkoll         ###   ########.fr       */
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
			ft_close(proc_list[i].pipe_out[1]);
			if (proc_list[i].proc_index > 0)
			{
				ft_close(proc_list[i].pipe_in[0]);
				ft_close(proc_list[i].pipe_out[1]);
			}
		}
		else if (proc_list[i].proc_index > 0)
			ft_close(proc_list[i].pipe_in[1]);
		i++;
	}
	return (0);
}

void	close_one_proc_fd(t_process *p)
{
	if (p->proc_index > 0)
	{
		ft_close(p->pipe_in[0]);
		ft_close(p->pipe_in[1]);
	}
	if (p->proc_index < p->proc_count - 1)
	{
		ft_close(p->pipe_out[0]);
		ft_close(p->pipe_out[1]);
	}
}
