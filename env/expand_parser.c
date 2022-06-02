/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:23:51 by cbignon           #+#    #+#             */
/*   Updated: 2022/06/02 17:38:46 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_internal.h"

void	to_keep_simple_quote(char *str, int *i, int *j, char *to_keep)
{
	int	closing_quote;
	int	quote;
	int	*in_dbl;

	in_dbl = get_dble_option();
	quote = (*i);
	closing_quote = (ft_strclen(str + (quote + 1), '\'')) + *i + 1;
	if (*in_dbl == 1)
		closing_quote = quote;
	if (str[closing_quote] != '\'')
		closing_quote = quote;
	while (str[(*i)] && (*i) <= closing_quote)
	{
		to_keep[(*j)] = str[(*i)];
		(*i)++;
		(*j)++;
	}
	to_keep[*j] = '\0';
}

void	to_keep_double_quote(char *str, int *i, char *to_keep, int *k)
{
	int	*in_dble;

	in_dble = get_dble_option();
	if (!str[*i])
		return ;
	to_keep[*k] = str[*i];
	(*i)++;
	(*k)++;
	to_keep[*k] = '\0';
	if (*in_dble == -1)
		*in_dble = 1;
	else if (*in_dble == 0)
		*in_dble = 1;
	else if (*in_dble == 1)
		*in_dble = 0;
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
}

int	*get_dble_option(void)
{
	static int	*in_dble;

	if (!in_dble)
	{
		in_dble = (int *)malloc_verify(sizeof(int));
		*in_dble = -1;
	}
	return (in_dble);
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
