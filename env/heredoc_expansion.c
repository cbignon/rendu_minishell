/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:49:22 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/03 10:58:31 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	keep_invalid_dollar_line(char *str, int *i, int *k, char *to_keep)
{
	int	tmp;

	tmp = 0;
	to_keep[(*k)++] = str[(*i)++];
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

void	to_keep_quote_heredoc(char *str, int *i, char *to_keep, int *k)
{
	to_keep[*k] = str[*i];
	(*i)++;
	(*k)++;
	to_keep[*k] = '\0';
}

char	*parse_dollar_line(char *str, int i, int j, char *full)
{
	char	*to_expand;
	char	*to_keep;
	int		k;

	to_expand = malloc_bzero(8191);
	to_keep = malloc_bzero(ft_strlen(str) + 1);
	k = 0;
	while (str[i])
	{
		j = 0;
		if ((str[i] == '$' && str[i + 1] && !ft_is_valid_var_char(str[i + 1]))
			|| (str[i] == '$' && !str[i + 1]))
			keep_invalid_dollar_line(str, &i, &k, to_keep);
		else if (str[i] == '$')
			to_expand_dollar(str, &i, to_expand, &j);
		else if (str[i] == '\'' || str[i] == '\"')
			to_keep_quote_heredoc(str, &i, to_keep, &k);
		else if (str[i] && str[i] != '\'' && str[i] != '$' && str[i] != '\"')
			to_keep_no_doll(str, &i, to_keep, &k);
		to_expand = ft_expand(to_expand, 0, 0);
		full = ft_accumulate(full, to_expand, to_keep, &k);
	}
	return (full);
}

char	*get_expanded_line(char *line)
{
	int		i;
	char	**tmp;
	char	**final;
	char	*ret;

	i = 0;
	if (ft_str_has_char(line, '$') == -1)
		return (line);
	//tmp = split_protect_quoted(line, ' ');
	tmp = ft_split(line, ' ');
	final = malloc_verify(sizeof(char *) * (ft_tablen(tmp) + 1));
	while (tmp[i])
	{
		if (ft_str_has_char(tmp[i], '$') == -1)
			final[i] = ft_strdup_cu(tmp[i]);
		else
			final[i] = parse_dollar_line(tmp[i], 0, 0, NULL);
		i++;
	}
	final[i] = NULL;
	ret = ft_tab_to_str(final, ' ', size_tab_to_str(final));
	ft_tabfree_cu((void ***)&tmp, ft_tablen(tmp), 0);
	ft_tabfree_cu((void ***)&final, ft_tablen(final), 0);
	return (ret);
}
