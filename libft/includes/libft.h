/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:28:36 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 12:27:57 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define INTMAX 2147483647
# define INTMIN (-INTMAX -1)
# include <string.h>
# include "get_next_line.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	size_t			length;
	t_list			*start;
}					t_stack;

void				*ft_memset(void *a, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int i, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *str1, const char *str2);
char				*ft_strncat(char *str1, const char *str2, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr(const char *stringbig, const char *stringsmall);
char				*ft_strnstr(const char *stringbig, const char *stringsmall,
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

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *str);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *str, char(*f)(unsigned int, char));
int					ft_strequ(char const *str1, char const *str2);
int					ft_strnequ(char const *str1, char const *str2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int num);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int num);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int num, int fd);
void				ft_puthex(int num);
void				ft_puthex_fd(int num, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *newlst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				ft_stackpush(t_stack *stack, t_list *new_node);
t_list				*ft_stackpop(t_stack *stack);
void				ft_stackqueue(t_stack *stack, t_list *new_node);
t_list				*ft_stackserve(t_stack *stack);
t_stack				*ft_stacknew(void);

int					ft_power(int base, int power);
int					ft_whitespace(char c);
int					ft_int_len(int num);
int					ft_int_len_neg(int num, int *neg);
int					ft_strcmp_simple(const char *s1, const char *s2);
int					ft_strncmp_simple(const char *s1, const char *s2,
										size_t len);
int					ft_nextdig(char *str);
char				*ft_strjoinfree(char *s1, char const *s2);

int					ft_atoi_long(const char *str);
int					ft_strcount(char **str);
int					ft_printf(char *input, ...);
int					ft_dprintf(int fd, char *input, ...);

void				ft_del_onlylist(t_list **alst);
void				ft_del_onlystack(t_stack **stack);
void				ft_stackdel(t_stack **stack, void (*del)(void*, size_t));
t_stack				*ft_stackdup(t_stack *stack);
t_list				*ft_lstdup(t_list *node);
void				ft_stackrev(t_stack *stack);
void				ft_lstaddfront(t_list **alst, t_list *new_lst);

int					ft_strinlist(char *str, char **list, int list_len);
int					ft_strinstack(char *str, t_stack *stack_x);

#endif
