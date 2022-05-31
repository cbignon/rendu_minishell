/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_env.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbignon <cbignon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:05:32 by cbignon           #+#    #+#             */
/*   Updated: 2022/04/20 11:21:28 by cbignon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_ENV_H
# define STRUCT_ENV_H

typedef struct s_env
{
	char	**loc_env;
	char	**gl_env;
}	t_env;

#endif