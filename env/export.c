/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:34:49 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/22 16:54:45 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	ft_export(t_process *p)
{
	char	***env;
	char	*var_name;
	char	*var_value;
	int		i;

	i = 0;
	env = choose_env(p);
	if (!p->args[1])
		return (ft_print_sorted_env(p->std_out, p->std_err, *env));
	while (p->args[++i])
	{
		p->args[i] = skip_quotes(p->args[i], 0);
		var_name = get_var_name(p->std_err, p->args[i]);
		if (var_name)
		{
			var_value = get_var_value(p->args[i]);
			if (!is_var_in_env(*env, var_name))
				ft_add_to_env(env, var_name, var_value);
			else
				modify_var_in_env(env, var_name, var_value);
		}
		else
			p->res = 1;
	}
}

void	ft_print_sorted_env(int std_out, int std_err, char **env)
{
	int		i;
	char	*tmp_name;
	char	*tmp_value;
	char	**to_print;

	to_print = NULL;
	to_print = ft_tabdup(env);
	if (!to_print)
		return ;
	to_print = (char **)ft_sort_tab((void **)to_print, ft_tablen(env));
	i = -1;
	while (to_print[++i])
	{
		ft_putstr_fd("declare -x ", std_out);
		tmp_name = get_var_name(std_err, to_print[i]);
		ft_putstr_fd(tmp_name, std_out);
		gc_delone((void **)&tmp_name, 0);
		ft_putchar_fd('"', std_out);
		tmp_value = get_var_value(to_print[i]);
		ft_putstr_fd(tmp_value, std_out);
		gc_delone((void **)&tmp_value, 0);
		ft_putstr_fd("\"\n", std_out);
	}
	ft_tabfree_cu((void ***)&to_print, ft_tablen(to_print), 0);
}

void	ft_add_to_env(char ***env, char *var_name, char *var_value)
{
	int				i;
	char			**new_env;
	char			*new_var;

	i = -1;
	new_var = NULL;
	new_var = ft_strjoin_cu(var_name, var_value);
	verify_ptr(new_var);
	new_env = malloc_verify(sizeof(char *) * (ft_tablen(*env) + 2));
	while (++i < ft_tablen(*env))
	{
		new_env[i] = ft_strdup_cu((*env)[i]);
		verify_ptr(new_env[i]);
	}
	new_env[i] = ft_strdup_cu(new_var);
	verify_ptr(new_env[i]);
	new_env[i + 1] = NULL;
	ft_tabfree_cu((void ***)&(*env), ft_tablen(*env), 0);
	*env = new_env;
	gc_delone((void **)&new_var, 0);
	gc_delone((void **)&var_name, 0);
	gc_delone((void **)&var_value, 0);
}

void	modify_var_in_env(char ***env, char *var_name, char *new_value)
{
	char			*var;
	char			**new_env;
	int				i;

	i = -1;
	var = NULL;
	new_env = NULL;
	var = ft_strjoin_cu(var_name, new_value);
	new_env = malloc_verify(sizeof(char *) * (ft_tablen(*env) + 1));
	while (++i < ft_tablen(*env))
	{
		if (ft_start_with((*env)[i], var_name))
			new_env[i] = ft_strdup_cu(var);
		else
			new_env[i] = ft_strdup_cu((*env)[i]);
	}
	new_env[i] = NULL;
	ft_tabfree_cu((void ***)&(*env), ft_tablen(*env), 0);
	*env = new_env;
	gc_delone((void **)&var, 0);
	gc_delone((void **)&var_name, 0);
	gc_delone((void **)&new_value, 0);
}
