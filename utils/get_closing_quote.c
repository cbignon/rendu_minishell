/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closing_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:55:00 by atron             #+#    #+#             */
/*   Updated: 2022/06/10 14:20:41 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

int	get_closing_quote(const char *str, char quote)
{
	int	index;

	index = 1;
	while (str[index])
	{
		if (str[index] == quote)
			return (index);
		index++;
	}
	return (0);
}
