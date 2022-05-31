/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:35:43 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/22 16:05:37 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	ft_remove_var(char ***env, char *var)
{
	int		i;
	int		j;
	char	**new_env;
	int		var_len;

	i = 0;
	j = 0;
	new_env = (char **)malloc_verify((sizeof(char *) * (ft_tablen(*env))));
	var_len = ft_strlen(var);
	if (!new_env)
		return ;
	while ((*env)[i])
	{
		if ((*env)[i + 1] && ft_strncmp((*env)[i], var, (var_len)) == 0)
			i++;
		if (!(*env)[i + 1] && ft_strncmp((*env)[i], var, (var_len)) == 0)
			break ;
		new_env[j] = ft_strdup_cu((*env)[i]);
		i++;
		j++;
	}
	new_env[j] = NULL;
	ft_tabfree_cu((void ***)&(*env), ft_tablen(*env), 0);
	*env = new_env;
}

void	ft_unset(t_process *p)
{
	int		i;
	char	**new_env;
	char	***env;
	char	*var_name;

	i = 0;
	new_env = NULL;
	env = choose_env(p);
	if (!p->args[1])
		return ;
	while (p->args[++i])
	{
		if (parse_var_name(p->args[i]) == 0)
			p->res = ft_printerr(p->std_err, p->cmd, p->args[i],
					" : not a valid identifier");
		else
		{
			var_name = ft_strjoin_cu(p->args[i], "=");
			if (ft_find_in_tab(*env, var_name))
				ft_remove_var(env, var_name);
			gc_delone((void **)&var_name, 0);
		}
	}
}
