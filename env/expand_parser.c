/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:23:51 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/26 16:20:22 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	to_expand_dollar(char *str, int *i, char *to_expand, int *j)
{
	int	doll;

	doll = 0;
	while (str[*i])
	{
		if (str[*i] == '$')
		{
			doll = *i;
			to_expand[(*j)++] = str[(*i)++];
			while (str[*i] && (ft_is_valid_var_char(str[*i]) || str[*i] == '?'))
			{
				if (*i == (doll + 1) && ft_isdigit(str[*i]))
				{
					to_expand[(*j)++] = str[(*i)++];
					to_expand[*j] = '\0';
					return ;
				}
				to_expand[(*j)++] = str[(*i)++];
			}
			if (str[(*i)] != '$' && str[(*i)] != '\"' && str[(*i)] != '\'')
				to_expand[(*j)++] = '\0';
		}
		else
			break ;
	}
}

void	to_keep_simple_quote(char *str, int *i, int *j, char *to_keep)
{
	int	dollar;
	int	closing_quote;

	dollar = ft_strclen((str + *i), '$') + *i;
	closing_quote = ft_strclen((str + dollar), '\'') + dollar + 1;
	while (str[(*i)])
	{
		if (str[*i] == '\"' || (*i > closing_quote && str[*i] == '$'))
			break ;
		else
			to_keep[(*j)++] = str[(*i)++];
	}
	to_keep[*j] = '\0';
	if (ft_str_has_char(to_keep, ' ') == -1 && ft_strlen(to_keep) > 2)
		skip_quotes(to_keep, 0);
}

void	to_keep_double_quote(char *str, int *i, char *to_keep, int *k)
{
	if (!str[*i])
		return ;
	while (str[*i] && str[*i] != '$')
	{
		to_keep[*k] = str[*i];
		(*i)++;
		(*k)++;
	}
	to_keep[*k] = '\0';
}

void	to_keep_no_doll(char *str, int *i, char *to_keep, int *j)
{
	if (!str[*i])
		return ;
	while (str[*i] && str[*i] != '$' && str[*i] != '\"' && str[*i] != '\'')
	{
		to_keep[(*j)] = str[(*i)];
		(*j)++;
		(*i)++;
	}
	to_keep[*j] = '\0';
	if (ft_str_has_char(to_keep, ' ') == -1)
		to_keep = skip_quotes(to_keep, 0);
}

char	*parse_dollar(char *str, int i, int j, char *full)
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
			keep_invalid_dollar(str, &i, &k, to_keep);
		else if (str[i] == '$')
			to_expand_dollar(str, &i, to_expand, &j);
		else if (str[i] == '\'')
			to_keep_simple_quote(str, &i, &k, to_keep);
		else if (str[i] == '\"')
			to_keep_double_quote(str, &i, to_keep, &k);
		else if (str[i] && str[i] != '\'' && str[i] != '$' && str[i] != '\"')
			to_keep_no_doll(str, &i, to_keep, &k);
		to_expand = ft_expand(to_expand, 0, 0);
		full = ft_accumulate(full, to_expand, to_keep, &k);
	}
	return (full);
}
