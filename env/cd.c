/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:13:30 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/20 10:59:11 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

int	ft_change_dir( int std_err, char *dir_n)
{
	struct stat	info;

	if (chdir(dir_n) == -1)
	{
		if (stat(dir_n, &info) == -1)
			return (ft_printerr(std_err, "cd", dir_n,
					" No such file or directory"));
		if (info.st_mode != __S_IFDIR)
			return (ft_printerr(std_err, "cd", dir_n,
					" Not a directory"));
		if (!info.st_mode || info.st_mode != S_IXUSR)
			return (ft_printerr(std_err, "cd", dir_n,
					" Permission denied"));
	}
	return (0);
}

int	ft_cd_home(t_process *p)
{
	char	*home;

	home = ft_getenv("HOME", p);
	if (home)
	{
		if (ft_change_dir(p->std_err, home) == -1)
			return (1);
	}
	else
	{
		ft_printerr(p->std_err, p->cmd, NULL, "HOME not set");
		return (1);
	}
	return (0);
}

int	ft_cd_oldpath(t_process *p)
{
	char	*old_pwd;

	old_pwd = ft_getenv("OLDPWD", p);
	if (old_pwd)
	{
		ft_putendl_fd(old_pwd, 1);
		if (ft_change_dir(p->std_err, old_pwd) == -1)
			return (1);
	}
	else
	{
		ft_printerr(p->std_err, "cd", NULL, "OLDPWD not set");
		return (-1);
	}
	return (0);
}

void	ft_cd(t_process *p)
{
	char	*oldpwd;
	char	***env;
	int		ct;

	env = choose_env(p);
	oldpwd = get_pwd();
	ct = ft_count_args(p->args);
	if (ct > 2)
		return ((void)ft_printerr(p->std_err, p->cmd, NULL,
				"Too many arguments"));
	if (ct == 1 || ft_str_equ(p->args[1], "~") || ft_str_equ(p->args[1], "--"))
		p->res = ft_cd_home(p);
	else if (ft_str_equ(p->args[1], "-"))
	{
		p->res = ft_cd_oldpath(p);
		if (p->res == -1)
			return ((void)(p->res = 1));
	}
	else
		p->res = ft_change_dir(p->std_err, p->args[1]);
	set_pwd(get_pwd(), env);
	set_old_pwd(oldpwd, env);
}
