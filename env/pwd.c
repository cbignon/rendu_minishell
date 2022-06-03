/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:41:21 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/03 11:21:43 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	ft_pwd(t_process *p)
{
	char	*pwd;

	pwd = NULL;
	pwd = get_pwd();
	if (pwd == NULL)
	{
		pwd = ft_getenv("PWD", p);
		// p->res = 1;
		// return ((void)ft_printerr(p->std_err, p->cmd, NULL, "Failed"));
	}
	ft_putendl_fd(pwd, p->std_out);
	gc_delone((void **)&pwd, 0);
}

char	*get_pwd(void)
{
	char	*pwd;
	char	*tmp;

	pwd = NULL;
	tmp = NULL;
	tmp = getcwd(NULL, 0);
	pwd = ft_strdup_cu(tmp);
	ft_free((void **)&tmp, 0);
	return (pwd);
}

void	set_old_pwd(char *pwd, char ***env)
{
	char	*tmp;

	if (!pwd)
		return ;
	tmp = ft_strdup_cu("OLDPWD=");
	if (!is_var_in_env(*env, tmp))
		ft_add_to_env(env, tmp, pwd);
	else
		modify_var_in_env(env, tmp, pwd);
	gc_delone((void **)&tmp, 0);
	gc_delone((void **)&pwd, 0);
}

void	set_pwd(char *pwd, char ***env)
{
	char	*tmp;

	if (!pwd)
		return ;
	tmp = ft_strdup_cu("PWD=");
	if (!is_var_in_env(*env, tmp))
		ft_add_to_env(env, tmp, pwd);
	else
		modify_var_in_env(env, tmp, pwd);
	gc_delone((void **)&tmp, 0);
	gc_delone((void **)&pwd, 0);
}
