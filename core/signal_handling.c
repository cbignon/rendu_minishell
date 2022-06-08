/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 11:32:58 by atron             #+#    #+#             */
/*   Updated: 2022/06/08 14:11:54 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "core.h"

struct sigaction	*get_sa_int(void)
{
	static struct sigaction	sa_int = {};

	sa_int.sa_sigaction = &int_handler;
	sa_int.sa_flags = SA_SIGINFO;
	return (&sa_int);
}

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

void	signal_init(t_bool is_exec)
{
	if (!is_exec)
	{
		if (sigaction(SIGINT, get_sa_int(), NULL))
			ft_exit("Signal error!", -1, 1);
		static struct sigaction ignore;
		ignore.sa_handler = SIG_IGN;
		if (sigaction(SIGQUIT, &ignore, NULL))
			ft_exit("Signal error!", -1, 1);
	}
	else
	{
		static struct sigaction sa_default;
		sa_default.sa_handler = SIG_DFL;
		if (sigaction(SIGINT, &sa_default, NULL))
			ft_exit("Signal error!", -1, 1);
		if (sigaction(SIGQUIT, &sa_default, NULL))
			ft_exit("Signal error!", -1, 1);
	}
}
