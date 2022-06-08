/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:32:58 by atron             #+#    #+#             */
/*   Updated: 2022/06/07 17:27:25 by Darkkoll         ###   ########.fr       */
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

void signal_init(t_bool is_exec)
{
	//sigemptyset(&sa_int.sa_mask);
	//sigemptyset(&sa_quit.sa_mask);
	if (is_exec)
	{
		if (signal(SIGINT, &int_handler))
			ft_exit("Signal error!", -1, 1);
		if (signal(SIGQUIT, SIG_IGN))
			ft_exit("Signal error!", -1, 1);
	}
	else
	{
		if (signal(SIGINT, SIG_DFL))
			ft_exit("Signal error!", -1, 1);
		if (signal(SIGQUIT, SIG_DFL))
			ft_exit("Signal error!", -1, 1);
	}
	// sigaddset(&sa_int.sa_mask, SIGINT);
	// sigaddset(&sa_quit.sa_mask, SIGINT);
}
