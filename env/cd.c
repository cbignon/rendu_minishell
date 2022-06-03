/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 13:13:30 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/03 10:05:55 by Darkkoll         ###   ########.fr       */
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

t_bool	find_in_cdpath(char *path, char *name)
{
	DIR *dir;
	struct dirent *info;

	dir = opendir(path);
	if (!dir)
		return (FALSE);
	info = readdir(dir);
	while (info)
	{
		printf("dirent: %s\n", info->d_name);
		if (ft_str_equ(info->d_name, name))
		{
			printf("d_name = name");
			closedir(dir);
			return (TRUE);
		}
		info = readdir(dir);
	}
	return (FALSE);
}

t_bool	is_absolute(const char *path)
{
	if (!path || path[0] != '/')
		return (FALSE);
	return (TRUE);
}

char	**get_relative(char *path)
{
	char	**res;
	char	**tmp;

	tmp = ft_split(path, '/');
	if (!tmp)
		return (NULL);
	res = malloc_verify(3 * sizeof(*res));
	res[2] = NULL;
	if (!ft_str_equ(tmp[0], "."))
		res[1] = ft_strdup_cu(tmp[0]);
	else if (tmp[1])
	{
		res[1] = ft_strdup_cu(tmp[1]);
		res[0] = ft_strdup_cu(path + 2);
		printf("pathé: %s\n", path + 2);
	}
	return (res);
}

//TODO:
char	*get_path(char *arg)
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
		printf("folder: %s\n", cdpath_tab[index]);
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
	int		ct;
	char	*path;

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
	{
		path = get_path(p->args[1]);
		printf("path: %p\n", path);
		if (path)
			p->res = ft_change_dir(p->std_err, path);
		else
			ft_printerr(p->std_err, p->cmd, NULL, "No such file or directory");
	}
	set_pwd(get_pwd(), env);
	set_old_pwd(oldpwd, env);
}
