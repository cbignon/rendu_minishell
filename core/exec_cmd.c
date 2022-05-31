/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:32:26 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/29 15:28:24 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

void	ft_export_res(int ret)
{
	char	*value;
	char	*var_name;
	t_env	*env;

	env = ft_get_environ();
	value = ft_itoa_cu(ret);
	var_name = ft_strdup_cu("LAST_RET_VALUE=");
	verify_ptr(var_name);
	if (is_var_in_env(env->gl_env, var_name))
		modify_var_in_env(&env->gl_env, var_name, value);
	else
		ft_add_to_env(&env->gl_env, var_name, value);
}

void	exec_cmd(t_process *p)
{
	char	***env;
	char	**path;

	env = choose_env(p);
	path = ft_get_path(*env);
	if (p->redir->type == STOPPED_HEREDOC)
		exit(130);
	setup_redirect(p);
	if (ft_is_builtin(p->cmd) == 1)
		launch_builtin(p);
	else if (ft_str_has_char(p->cmd, '/') > -1)
		ft_exec_bin(p);
	else if (!path)
		p->res = 126 + ft_printerr(p->std_err, p->cmd, NULL,
				"No such file or directory");
	else if (ft_get_bin_path(p->cmd, *env) != NULL)
		ft_exec_bin(p);
	else
		p->res = 126 + ft_printerr(p->std_err, p->cmd, NULL,
				"command not found");
	ft_export_res(p->res);
}

static void	child_process(t_process *p)
{
	if (p->proc_index < p->proc_count - 1)
	{
		close(p->pipe_out[0]);
		dup2(p->pipe_out[1], STDOUT_FILENO);
		close(p->pipe_out[1]);
	}
	if (p->proc_index > 0)
	{
		close(p->pipe_in[1]);
		dup2(p->pipe_in[0], STDIN_FILENO);
		close(p->pipe_in[0]);
	}
	close_fd(p);
	exec_cmd(p);
	exit(p->res);
}

void	fork_cmd(t_process *p)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		p->res = ft_printerr(p->std_err, p->cmd, *p->args, "fork failed");
		p->pid = pid;
		return ;
	}
	if (pid == 0)
		child_process(p);
	else
		p->pid = pid;
}
