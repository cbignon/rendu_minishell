/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:32:22 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/07 11:10:16 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"
#include "core.h"

extern char		**environ;

char	***choose_env(t_process *p)
{
	t_env	*env;

	if (!p || (p->proc_count == 1 && ft_is_builtin(p->cmd)))
	{
		env = ft_get_environ();
		return (&(env->gl_env));
	}
	else
	{
		ft_dup_environ(p);
		return (&(p->env->gl_env));
	}
}

t_env	*ft_get_environ(void)
{
	static t_env	*env;
	int				i;
	int				tab_len;

	i = 0;
	tab_len = 0;
	if (!env)
	{
		if (environ)
			tab_len = ft_tablen(environ);
		env = (t_env *)malloc_verify(sizeof(t_env));
		env->gl_env = (char **)malloc_verify(sizeof(char *)
				* (tab_len + 1));
		while (i < tab_len)
		{
			env->gl_env[i] = ft_strdup_cu(environ[i]);
			verify_ptr(env->gl_env[i]);
			i++;
		}
		env->gl_env[i] = NULL;
	}
	return (env);
}

void	ft_dup_environ(t_process *p)
{
	t_env	*env;
	int		i;

	env = ft_get_environ();
	i = 0;
	if (p->env == NULL)
	{
		p->env = (t_env *)malloc_verify(sizeof(t_env));
		p->env->gl_env = (char **)malloc_verify(sizeof(char *)
				* (ft_tablen(env->gl_env) + 1));
		while (env->gl_env[i])
		{
			p->env->gl_env[i] = ft_strdup_cu(env->gl_env[i]);
			verify_ptr(p->env->gl_env[i]);
			i++;
		}
		p->env->gl_env[i] = NULL;
	}
}
