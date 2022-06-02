/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:35:26 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/27 15:42:07 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

static void	copy_no_quote(char *str, int length, int *lst)
{
	int	index;
	int	tmp;

	index = 0;
	tmp = 0;
	if (!str)
		return ;
	while (index < length)
	{
		while (in_index(lst, tmp))
			tmp++;
		str[index++] = str[tmp++];
	}
	str[index] = '\0';
}

char	*skip_quotes(char *str, int index)
{
	int		length;
	int		tmp;
	int		*lst;

	length = 0;
	lst = NULL;
	while (str && str[index])
	{
		if (is_quote(str[index]))
		{
			lst = append_index(lst, index);
			tmp = get_closing_quote(str + index, str[index]);
			length = length + tmp - 1;
			index = index + tmp;
			lst = append_index(lst, index);
		}
		else
			length++;
		index++;
	}
	copy_no_quote(str, length, lst);
	return (str);
}
