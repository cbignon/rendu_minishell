/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_results.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 12:00:58 by root              #+#    #+#             */
/*   Updated: 2021/11/22 11:50:07 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RESULTS_H
# define FT_RESULTS_H

# include <math.h>
# include "ft_def.h"

typedef struct s_double_pair
{
	double_t	first;
	double_t	second;
}	t_double_pair;

typedef struct s_double_result
{
	t_bool		result;
	char		*message;
	double_t	value;
}	t_double_result;

#endif
