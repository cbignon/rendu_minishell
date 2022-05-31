/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_tab_or_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 20:08:09 by cbignon           #+#    #+#             */
/*   Updated: 2022/03/28 20:08:39 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

int	first_space_or_quote(char *str, int i)
{
	int	space;
	int	quote;

	space = -1;
	quote = -1;
	while (str[i])
	{
		if (quote == -1 && (str[i] == '\'' || str[i] == '\"'))
			quote = i;
		else if (space == -1 && (str[i] == ' ' || str[i] == '\0'))
			space = i;
		i++;
	}
	if (quote == -1)
		return (1);
	else if (space == -1 && quote > -1)
		return (2);
	else if (space < quote)
		return (1);
	else if (quote < space)
		return (2);
	else
		return (0);
}
