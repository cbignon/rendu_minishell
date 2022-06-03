/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntax_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:22:02 by atron             #+#    #+#             */
/*   Updated: 2022/06/03 14:20:07 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

t_bool	is_quote(char c)
{
	if (c == '\"' || c == '\'')
		return (TRUE);
	return (FALSE);
}

int	space_str(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (2);
}

int	skip_spaces(char *cmd)
{
	int	index;

	index = 0;
	if (!cmd)
		return (0);
	while (cmd[index])
	{
		if (cmd[index] != ' ')
			return (index);
		index++;
	}
	return (index);
}

int	verify_syntax(char *cmd)
{
	int	index;
	int	tmp;

	if (space_str(cmd) == 2)
		return (2);
	if (is_meta(cmd[ft_strlen(cmd) - 1]))
		return (1);
	index = skip_spaces(cmd);
	if (cmd[index] == '|')
		return (-1);
	while (cmd[index])
	{
		if (is_quote(cmd[index]))
		{
			tmp = get_closing_quote(&cmd[index], cmd[index]);
			if (!tmp)
				return (1);
			index += tmp;
		}
		else if (is_meta(cmd[index]))
			if (!verify_meta(cmd, index))
				return (-1);
		index++;
	}
	return (0);
}
