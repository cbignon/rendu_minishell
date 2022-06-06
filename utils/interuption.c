/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interuption.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Darkkoll <Darkkoll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 16:05:10 by Darkkoll          #+#    #+#             */
/*   Updated: 2022/06/06 16:05:26 by Darkkoll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_internal.h"

t_bool	get_interuption(t_bool value)
{
	static t_bool	interup = FALSE;

	if (value == TRUE || value == FALSE)
		interup = value;
	return (interup);
}