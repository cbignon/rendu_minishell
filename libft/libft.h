/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atron <atron@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:01:12 by atron             #+#    #+#             */
/*   Updated: 2021/05/18 14:38:57 by atron            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include "ft_def.h"
# include "ft_results.h"
# ifdef UNIX
#  include <unistd.h>
# elif WINDOWS
#  include <io.h>
# endif
# include <stdlib.h>
# include <limits.h>

# define INT_MIN_STR "-2147483648"
# define INT_MAX_STR "2147483647"
# define UINT_MAX_STR "4294967295"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

typedef struct s_fd
{
	int		fd;
	char	*save;
}	t_fd;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_gc
{
	t_list	*ptr_list;
}	t_gc;

char			*ft_strdup(const char *src);
char			*ft_strndup(const char *src, size_t len);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strnjoin(char const *s1, unsigned int s1_size,
					char const *s2, unsigned int s2_size);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
int				ft_chara_count(char *str);
char			*ft_itoa(int n);
char			*ft_itoa_cu(int n);
t_bool			ft_atoi(char *str, int *out);
t_double_result	ft_atof(char *str);
int64_t			ft_atoll(char *str);
unsigned int	ft_atoui(char *str);
uint64_t		ft_atoull(char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
t_bool			is_full_digit(char *str);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_realloc(void **src, unsigned int src_size,
					unsigned int dest_size);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_calloc_init(size_t nmemb, int c, size_t size);
char			*get_empty_str(void);
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putendl_fd(char *s, int fd);
int				ft_putunbr_fd(unsigned int n, int fd);
int				ft_putnbr_base_fd(int n, char *base, int fd);
int				ft_putunbr_base_fd(unsigned int n, char *base, int fd);
int				ft_putulnbr_base_fd(unsigned long n, char *base, int fd);
int				ft_putullnbr_base_fd(uint64_t n, char *base, int fd);
size_t			ft_strlen(char *str);
size_t			ft_strclen(char *str, char c);
size_t			ft_strnlen(char *str, int size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
t_list			*ft_lstfind(t_list **prev, t_list **next, void *ptr);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *element);
int				ft_lstsize(t_list *lst);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstadd_back(t_list **alst, t_list *element);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *),
					void (*del)(void *));
t_fd			*ft_get_fd(t_fd **lst, int fd, int index);
int				ft_free(void **ptr, int out);
int				get_next_line(char fd, char **line);
char			*ft_tabjoin(char **tab, unsigned int tab_size,
					unsigned int str_size);
int				ft_stristr(const char *s1, const char *s2, size_t len);
int				ft_tabfree(void ***tab, int size, int out);
int				ft_tablen(char **tab);
void			ft_exit(char *message, int return_value, int fd);
char			*ft_strjoin_free_cu(char const *s1, char const *s2,
					int (del)(void **, int));

/*Functions for custom allocator*/
/******************************************************************************/

char			*ft_strdup_cu(const char *src);
void			*ft_calloc_init_cu(size_t nmemb, int c, size_t size);
void			*ft_calloc_cu(size_t nmemb, size_t size);
char			*ft_strndup_cu(const char *src, size_t len);
char			*ft_substr_cu(char const *s, unsigned int start, size_t len);
char			*ft_strtrim_cu(char const *s1, char const *set);
char			*ft_tabjoin_cu(char **tab, unsigned int tab_size,
					unsigned int str_size);
char			*ft_strjoin_cu(char const *s1, char const *s2);
void			*ft_realloc_cu(void **src, unsigned int src_size,
					unsigned int dest_size);
int				ft_tabfree_cu(void ***tab, int size, int out);

/*Garbage Collector*/
/******************************************************************************/

void			gc_init(void);
void			*gc_malloc(size_t size);
int				gc_delone(void **ptr, int out);
int				gc_clear(int out);
void			*move_to_gc(void **ptr, size_t size);
void			*malloc_verify(int size);
void			verify_ptr(void *ptr);
void			*malloc_bzero(int size);
void			*malloc_verify_ncu(int size);

#endif
