/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_dollar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:07:08 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/26 16:19:23 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

char	*ft_get_expanded_cmd(char *cmd)
{
	int		i;
	char	**tmp;
	char	**final;
	char	*ret;

	i = 0;
	if (ft_str_has_char(cmd, '$') == -1)
		return (cmd);
	tmp = split_protect_quoted(cmd, ' ');
	final = malloc_verify(sizeof(char *) * (ft_tablen(tmp) + 1));
	while (tmp[i])
	{
		if (ft_str_has_char(tmp[i], '$') == -1)
			final[i] = ft_strdup_cu(tmp[i]);
		else
			final[i] = parse_dollar(tmp[i], 0, 0, NULL);
		i++;
	}
	final[i] = NULL;
	ret = ft_tab_to_str(final, ' ', size_tab_to_str(final));
	ft_tabfree_cu((void ***)&tmp, ft_tablen(tmp), 0);
	ft_tabfree_cu((void ***)&final, ft_tablen(final), 0);
	return (ret);
}

void	keep_invalid_dollar(char *str, int *i, int *k, char *to_keep)
{
	int	tmp;

	tmp = 0;
	if (str[(*i) + 1] && (str[(*i) + 1] == '\'' || str[(*i) + 1] == '\"'
			|| ft_isdigit(str[(*i) + 1])))
		(*i)++;
	while (str[*i])
	{
		if (str[*i] == '\"')
			tmp = get_closing_quote(str + (*i), '\"') + (*i);
		else if (str[*i] == '\'')
			tmp = get_closing_quote(str + (*i), '\'') + (*i);
		if (tmp)
		{
			while (*i <= tmp)
				to_keep[(*k)++] = str[(*i)++];
			break ;
		}
		to_keep[(*k)++] = str[(*i)++];
		if (str[*i] == '$' || str[*i] == ' ')
			break ;
	}
	to_keep[*k] = '\0';
}
