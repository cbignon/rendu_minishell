/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_internal.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:58:51 by atron             #+#    #+#             */
/*   Updated: 2022/06/10 14:21:23 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SPLIT_INTERNAL_H
# define FT_SPLIT_INTERNAL_H

# include <stdlib.h>
# include "libft.h"
# include "ft_split.h"
# include "utils.h"

typedef struct s_arg_info
{
	char	*start;
	int		length;
}	t_arg_info;

t_arg_info	*get_args_info(char *str);
t_arg_info	*realloc_arg_info(t_arg_info *args_info, int out_size);
t_arg_info	*calloc_arg_info(int size);
int			pass_white_space(int i, char *str);
int			get_arg_length(char *str, int length);
int			get_arg_count(t_arg_info	*args_info);

#endif
