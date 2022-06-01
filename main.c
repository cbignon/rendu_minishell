/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 12:06:17 by atron             #+#    #+#             */
/*   Updated: 2022/06/01 13:54:12 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "env.h"
#include "errno.h"
#include "libft.h"
#include "processes.h"
#include "utils.h"
#include <dirent.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static char	*invalid_cmd(char *cmd)
{
	ft_printerr(2, cmd, NULL, "Invalid Command!");
	gc_delone((void **)&cmd, 0);
	return (get_empty_str());
}

char	*read_cmd(void)
{
	int		is_valid;
	char	*cmd;
	int		size;

	is_valid = 0;
	cmd = NULL;
	cmd = readline(get_prompt());
	while (TRUE)
	{
		if (!cmd)
			return (NULL);
		size = ft_strlen(cmd) + 1;
		cmd = move_to_gc((void **)&cmd, size);
		cmd[size - 1] = '\0';
		is_valid = verify_syntax(cmd);
		if (is_valid == 2)
			return (get_empty_str());
		add_history(cmd);
		if (is_valid == -1)
			return (invalid_cmd(cmd));
		else if (!is_valid)
			break ;
		cmd = ft_strjoin_cu(cmd, readline(">"));
	}
	return (cmd);
}

void	minishell(void)
{
	t_process	*processes;
	char		*cmd;

	while (TRUE)
	{
		cmd = read_cmd();
		if (!cmd)
		{
			rl_clear_history();
			ft_exit("exit", 0, 1);
		}
		else if (*cmd != '\0')
		{
			processes = setup_processes(cmd);
			clean_quotes(processes);
			setup_heredocs(processes);
			run_processes(processes);
			wait_processes(processes);
		}
		clean_processes();
		gc_delone((void **)&cmd, 0);
	}
}

int	main(void)
{
	struct sigaction	sa_int;
	struct sigaction	sa_self;

	sigemptyset(&sa_int.sa_mask);
	sigemptyset(&sa_self.sa_mask);
	sa_int.sa_sigaction = &int_handler;
	sa_int.sa_flags = SA_SIGINFO;
	if (sigaction(SIGINT, &sa_int, NULL))
		ft_exit("Signal error!", -1, 1);
	sigaddset(&sa_int.sa_mask, SIGINT);
	minishell();
	rl_clear_history();
	return (0);
}
