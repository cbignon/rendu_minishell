/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 09:55:52 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/27 15:35:45 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

int	parse_var_name(char *var_name)
{
	int	i;

	i = 0;
	while (var_name[i])
	{
		if (i == 0 && !ft_isalpha(var_name[i]) && var_name[i] != '_')
			return (0);
		else if (!ft_isalpha(var_name[i]) && !ft_isdigit(var_name[i])
			&& var_name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

char	*get_var_name(int std_err, char *var)
{
	int		len;
	char	*var_name;
	char	*tmp;

	var_name = NULL;
	len = ft_strclen(var, '=');
	var_name = ft_strndup_cu(var, len);
	if (len == 0 || parse_var_name(var_name) == 0)
	{
		ft_printerr(std_err, "export", var, " : not a valid identifier");
		gc_delone((void **)&var_name, 0);
		return (NULL);
	}
	if (var[len] != '=')
		return (NULL);
	tmp = ft_strjoin_cu(var_name, "=");
	gc_delone((void **)&var_name, 0);
	return (tmp);
}

char	*get_var_value(char *var)
{
	char	*var_value;
	int		len;

	var_value = NULL;
	len = ft_strclen(var, '=');
	var_value = ft_substr_cu(var, len + 1, ((int)ft_strlen(var) - len));
	return (var_value);
}

int	is_quoted(char *str)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			q++;
		i++;
	}
	if (q > 0)
		return (1);
	return (0);
}
