/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:47:19 by atron             #+#    #+#             */
/*   Updated: 2022/06/10 14:20:58 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libft.h"
# include <stdio.h>

char	*ft_find_in_tab(char **tab_str, char *str);
char	*ft_start_with(char *str, char *s);
char	**ft_tabcpy(char **tab);
char	**ft_tabdup(char **tab);
char	**ft_tabdup_cu(char **tab);
char	**ft_tabncpy(char **tab, int n);
int		ft_str_equ(char *s1, char *s2);
char	**ft_read_dir(char *dir_name);
void	**ft_sort_tab(void **tab, int tab_len);
int		ft_printerr(int std_out, char *cmd, char *arg, char *msg);
int		ft_is_dir(char *name);
int		verify_syntax(char *cmd);
t_bool	is_meta(char c);
char	*ft_tab_to_str(char **tab, char c, int final_len);
int		size_tab_to_str(char **tab);
char	*ft_tab_to_simple_str(char **tab);
int		first_space_or_quote(char *str, int i);
int		get_closing_quote(const char *str, char quote);
int		verify_syntax(char *cmd);
t_bool	is_quote(char c);
int		*append_index(int *lst, int elem);
t_bool	in_index(int *lst, int value);
char	*skip_quotes(char *str, int index);
char	*ft_readline(char *prompt);
t_bool	verify_meta(char *str, int index);
t_bool	get_interuption(t_bool value);

#endif
