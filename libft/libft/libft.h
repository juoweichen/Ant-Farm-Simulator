/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:28:17 by juochen           #+#    #+#             */
/*   Updated: 2018/04/19 01:08:21 by juochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"

# define ABS(v) ((v) < 0 ? -(v) : (v))

typedef	struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;
/*
**		part 1
*/
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void*src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*
**		part 2
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
/*
**		bonus
*/
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
**		extra functions
*/
int					ft_words_count(const char *str, char c);
int					*ft_words_pos(const char *str, char c, int wcount);
int					ft_isspace(char c);
int					ft_isprime(int nb);
void				ft_sort_int_tab(int *tab, unsigned int size);
int					ft_numlen(int n);
void				ft_putnstr(char const *s, size_t n);
char				*ft_itoa_base_uint_lower(uintmax_t value, uintmax_t base);
char				*ft_itoa_base_uint_upper(uintmax_t value, uintmax_t base);
char				*ft_itoa_base_lower(intmax_t value, intmax_t base);
char				*ft_itoa_base_upper(intmax_t value, intmax_t base);
void				ft_putwstr(wchar_t const *s);
void				ft_putwchar(wchar_t c);
size_t				ft_wstrlen(const wchar_t *wstr);
void				ft_lstaddend(t_list **alst, t_list *new);
void				ft_mstr_sort(char **mstr);
void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putwstr_fd(wchar_t const *s, int fd);
void				ft_putnstr_fd(char const *s, size_t n, int fd);
int					ft_isdigit_str(char *str);
int					ft_isintsafe_str(char *str);
void				ft_mstrdel_norows(char ***mstr);
void				ft_mstrdel_rows(char ***mstr, int rows);
void				ft_lstdel_content(void *content, size_t content_size);
void				ft_swap_int(int *x, int *y);
void				ft_swap_double(double *x, double *y);
void				ft_sort_double_tab(double *tab, unsigned int size);
int					ft_skipline(int fd);
int					ft_strchri(char *s, char c);

#endif
