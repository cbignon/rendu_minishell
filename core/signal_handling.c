/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:32:58 by atron             #+#    #+#             */
/*   Updated: 2022/04/25 15:53:44 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "core.h"

void	kill_subs(void)
{
	t_process	**processes;
	int			index;

	processes = get_processes(0);
	if (!processes || !*processes)
		return ;
	index = 0;
	while ((*processes)[index].val)
	{
		if ((*processes)[index].pid > 0)
		{
			kill((*processes)[index].pid, SIGSTOP);
			kill((*processes)[index].pid, SIGCONT);
			kill((*processes)[index].pid, SIGQUIT);
		}
		index++;
	}
}

void	sub_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
	exit(0);
}

void	int_handler(int sig, siginfo_t *info, void *context)
{
	t_process	*p;

	(void)sig;
	(void)info;
	(void)context;
	p = *get_processes(0);
	kill_subs();
	ft_export_res(130);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (!p)
	{
		ft_putendl_fd("", 1);
		rl_redisplay();
	}
	else
		ft_putstr_fd("\n", 1);
}
