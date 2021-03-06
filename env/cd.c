/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:13:30 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/10 13:37:52 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

int	ft_change_dir( int std_err, char *dir_n)
{
	struct stat	info;
	DIR			*dp;

	dp = opendir(dir_n);
	if (!dp)
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
		return (0);
	}
	closedir(dp);
	if (chdir(dir_n) == -1)
	{
		return (ft_printerr(std_err, "cd", dir_n, " can't change dir"));
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

void	ft_cd_oldpath(t_process *p)
{
	char	*old_pwd;

	old_pwd = ft_getenv("OLDPWD", p);
	if (old_pwd)
	{
		ft_putendl_fd(old_pwd, 1);
		if (ft_change_dir(p->std_err, old_pwd) == -1)
			p->res = 1;
	}
	else
	{
		ft_printerr(p->std_err, "cd", NULL, "OLDPWD not set");
			p->res = 1;
	}
}

char	*get_cdpath(char *arg)
{
	char	*cdpath;
	char	**cdpath_tab;
	int		index;
	char	*res;
	char	**test;

	cdpath = ft_getenv("CDPATH", NULL);
	if (cdpath == NULL || is_absolute(arg))
		return (arg);
	test = get_relative(arg);
	cdpath_tab = ft_split(cdpath, ':');
	index = 0;
	while (cdpath_tab[index])
	{
		if (find_in_cdpath(cdpath_tab[index], test[1]))
			break ;
		index++;
	}
	if (!cdpath_tab[index])
		return (NULL);
	res = ft_strjoin_cu(cdpath_tab[index], "/");
	res = ft_strjoin_cu(res, arg);
	return (res);
}

void	ft_cd(t_process *p)
{
	char	*oldpwd;
	char	***env;
	char	*path;

	env = choose_env(p);
	oldpwd = get_pwd();
	if (ft_count_args(p->args) > 2)
		return ((void)ft_printerr(p->std_err, p->cmd, NULL,
				"Too many arguments"));
	if (ft_count_args(p->args) == 1 || ft_str_equ(p->args[1], "~")
		|| ft_str_equ(p->args[1], "--"))
		p->res = ft_cd_home(p);
	else if (ft_str_equ(p->args[1], "-"))
		ft_cd_oldpath(p);
	else
	{
		path = get_cdpath(p->args[1]);
		if (path)
			p->res = ft_change_dir(p->std_err, path);
		else
			ft_printerr(p->std_err, p->cmd, NULL, "No such file or directory");
	}
	set_pwd(get_pwd(), env);
	set_old_pwd(oldpwd, env);
}
