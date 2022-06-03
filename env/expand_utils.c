/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:35:12 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/02 17:39:48 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

static char	*substitution(char *str)
{
	char	*new_str;

	if (search_in_env_global(str))
		new_str = get_value_from_global(str);
	else
		new_str = substitute_not_in_env(str);
	return (new_str);
}

char	*ft_expand(char *str, int j, int i)
{
	char	**tmp;

	if (str[0] == '\0')
		return (str);
	tmp = malloc_verify(sizeof(char *)
			* (count_dollar(str, ft_strlen(str)) + 1));
	while (j < count_dollar(str, ft_strlen(str)))
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] != '?')
		{
			tmp[j] = ft_substr_cu(str, i + 1, (get_dollar_len(str, i) - 1));
			i += ft_strlen(tmp[j]) + 1;
		}
		else if (str[i] == '$' && str[i + 1])
		{
			tmp[j] = ft_strdup_cu("LAST_RET_VALUE");
			i += 2;
		}
		tmp[j] = substitution(tmp[j]);
		j++;
	}
	tmp[count_dollar(str, ft_strlen(str))] = NULL;
	return (ft_tab_to_simple_str(tmp));
}

int	check_var_name(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

char	*substitute_not_in_env(char *str)
{
	char	*no_dollar;

	if (ft_str_equ(str, "LAST_RET_VALUE"))
		return (ft_strdup_cu("0"));
	if (str[0] == '$')
		no_dollar = str + 1;
	else
		no_dollar = str;
	if (check_var_name(no_dollar) == 0)
		return (get_empty_str());
	else
		return (str);
}

char	*ft_accumulate(char *full, char *to_expand, char *to_keep, int *k)
{
	char	*tmp;

	tmp = NULL;
	if (!full)
	{
		full = ft_strjoin_cu(to_keep, to_expand);
		verify_ptr(full);
		ft_bzero(to_expand, ft_strlen(to_expand));
		ft_bzero(to_keep, ft_strlen(to_keep));
		*k = 0;
	}
	else
	{
		tmp = ft_strjoin_cu(to_keep, to_expand);
		verify_ptr(tmp);
		full = ft_strjoin_cu(full, tmp);
		verify_ptr(full);
		ft_bzero(to_expand, ft_strlen(to_expand));
		ft_bzero(to_keep, ft_strlen(to_keep));
		*k = 0;
	}
	return (full);
}
