/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:13:54 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/08 15:04:46 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

int	ft_is_builtin(char *cmd)
{
	if (ft_str_equ(cmd, "echo") || ft_str_equ(cmd, "export")
		|| ft_str_equ(cmd, "env") || ft_str_equ(cmd, "unset")
		|| ft_str_equ(cmd, "cd") || ft_str_equ(cmd, "pwd")
		|| ft_str_equ(cmd, "exit"))
		return (1);
	return (0);
}

int	launch_builtin(t_process *p)
{
	if (ft_str_equ(p->cmd, "echo"))
		ft_echo(p);
	else if (ft_str_equ(p->cmd, "cd"))
		ft_cd(p);
	else if (ft_str_equ(p->cmd, "pwd"))
		ft_pwd(p);
	else if (ft_str_equ(p->cmd, "env"))
		ft_env(p);
	else if (ft_str_equ(p->cmd, "export"))
		ft_export(p);
	else if (ft_str_equ(p->cmd, "unset"))
		ft_unset(p);
	else if (ft_str_equ(p->cmd, "exit"))
		exit_builtin(p);
	close_one_proc_fd(p);
	return (0);
}
