/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_empty_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:17:14 by atron             #+#    #+#             */
/*   Updated: 2022/06/08 06:16:52 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_empty_str(void)
{
	char	*str;

	str = (char *)malloc_verify(1);
	if (str)
		str[0] = '\0';
	return (str);
}
