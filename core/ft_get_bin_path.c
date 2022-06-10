/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bin_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 17:28:45 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/10 13:26:20 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core_internal.h"

char	*get_full_binpath(char *dir, DIR *dp, struct dirent *dirp)
{
	char	*dir_name;
	char	*final_path;

	dir_name = ft_strjoin_cu(dir, "/");
	verify_ptr(dir_name);
	final_path = ft_strjoin_cu(dir_name, dirp->d_name);
	verify_ptr(final_path);
	gc_delone((void **)&dir_name, 0);
	closedir(dp);
	return (final_path);
}

char	*ft_get_bin_path(char *cmd, char **env)
{
	char	**path;
	char	*bin_path;

	path = ft_get_path(env);
	if (!path)
		return (NULL);
	bin_path = find_in_path(path, cmd);
	ft_tabfree_cu((void ***)&path, (ft_tablen(path)), 0);
	return (bin_path);
}

static void	exec_no_binpath(t_process *p)
{
	gc_clear(0);
	p->res = ft_printerr(p->std_err, p->cmd, NULL, "no such file or directory");
}

void	exec_prep(char ***tab, char ***en, char ***env, t_process *p)
{
	*tab = ft_tabdup(p->args);
	if (!*tab)
		ft_exit("Malloc Error!", 2, 2);
	*en = ft_tabdup(*env);
	if (!*en)
	{
		ft_tabfree((void ***)tab, ft_tablen(*tab), 0);
		ft_exit("Malloc Error!", 2, 2);
	}
	gc_clear(0);
}

void	ft_exec_bin(t_process *p)
{
	char		*bin_path;
	char		**tab;
	char		***env;
	char		**en;
	struct stat	info;

	env = choose_env(p);
	bin_path = ft_strdup(p->cmd);
	if (ft_str_has_char(p->cmd, '/') == -1)
		bin_path = ft_strdup(ft_get_bin_path(p->cmd, *env));
	if (bin_path)
	{
		exec_prep(&tab, &en, env, p);
		signal_init(TRUE);
		if (execve(bin_path, tab, en) == -1)
		{
			ft_printerr(2, bin_path, NULL, "no such file or directory");
			clean_exec_failed(tab, en, bin_path);
			exit(127);
		}
		if (stat(bin_path, &info) == 0)
			exit(126);
	}
	else
		exec_no_binpath(p);
}
