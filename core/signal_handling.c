/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:32:58 by atron             #+#    #+#             */
/*   Updated: 2022/06/08 10:39:51 by cbignon          ###   ########.fr       */
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

void	int_handler(int sig)
{
	t_process	*p;

	(void)sig;
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

void	signal_init(t_bool is_exec)
{
	if (!is_exec)
	{
		if (signal(SIGINT, &int_handler) == SIG_ERR)
			ft_exit("MAIN SIG INT : Signal error!", -1, 1);
		if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
			ft_exit("MAIN SIG IGN : Signal error!", -1, 1);
	}
	else
	{
		if (signal(SIGINT, SIG_DFL) == SIG_ERR)
			ft_exit("CHILD SIGINT : Signal error!", -1, 1);
		if (signal(SIGQUIT, SIG_DFL) == SIG_ERR)
			ft_exit("CHILD SIGQUIT : Signal error!", -1, 1);
	}
}
