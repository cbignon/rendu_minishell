/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_wait_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:37:58 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/01 13:32:17 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "env.h"
#include "errno.h"
#include "libft.h"
#include "processes.h"
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static int	get_status(int status)
{
	int	res;

	res = 0;
	if (WIFEXITED(status))
		res = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		res = WTERMSIG(status) + 128;
	return (res);
}

void	wait_processes(t_process *processes)
{
	int			status;
	int			pid;
	t_process	*p;
	int			res;

	pid = 1;
	while (pid > 0)
	{
		pid = wait4(0, &status, WUNTRACED, NULL);
		if (pid == -1)
			return (kill_subs());
		else if (pid == 0)
			return ;
		res = get_status(status);
		if (res == 3)
			ft_exit("MALLOC ERROR!", 2, 2);
		p = find_process(processes, pid);
		if (!p)
			continue ;
		p->res = res;
		close_one_proc_fd(p);
		ft_export_res(p->res);
	}
}

void	run_processes(t_process *processes)
{
	int			index;
	//int			status;
	//t_process	*p;

	//status = 0;
	index = 0;
	//p = NULL;
	create_pipe(processes);
	while (processes[index].val)
	{
		if (ft_is_builtin(processes[index].cmd)
			&& processes[index].proc_count == 1)
			exec_cmd(processes);
		else
			fork_cmd(&processes[index]);
		index++;
	}
}
