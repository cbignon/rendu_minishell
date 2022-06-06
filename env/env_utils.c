/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:19:40 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/03 20:22:32 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

int	is_var_in_env(char **env, char *var_name)
{
	int		i;

	i = 0;
	if (!var_name || var_name[i] == '\0' || !env)
		return (0);
	if (ft_find_in_tab(env, var_name))
		return (1);
	return (0);
}

void	ft_print_env(char **env, int std_out)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putendl_fd(env[i], std_out);
		i++;
	}
}

char	*ft_getenv(char *name, t_process *p)
{
	char	*value;
	char	*to_find;
	char	***env;
	int		len;

	env = choose_env(p);
	value = NULL;
	if (!*env)
	{
		printf("env not set\n");
		return (NULL);
	}
	to_find = ft_strjoin_cu(name, "=");
	verify_ptr(to_find);
	value = ft_find_in_tab(*env, to_find);
	gc_delone((void **)&to_find, 0);
	if (value)
	{
		len = ft_strclen(value, '=');
		//if (value + (len + 1))
		return (value + len + 1);
		//else
		//	return (get_empty_str());
	}
	return (NULL);
}

int	search_in_env_global(char *str)
{
	t_env	*env;
	char	*to_find;

	env = ft_get_environ();
	to_find = ft_strjoin_cu(str, "=");
	verify_ptr(to_find);
	if (is_var_in_env(env->gl_env, to_find))
		return (1);
	return (0);
}

char	*get_value_from_global(char *var_name)
{
	t_env	*env;
	char	*ret;
	char	*line;

	env = ft_get_environ();
	line = ft_strdup_cu(ft_find_in_tab(env->gl_env, var_name));
	verify_ptr(line);
	ret = get_var_value(line);
	return (ret);
}
