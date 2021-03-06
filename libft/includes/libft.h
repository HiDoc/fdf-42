/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmadura <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:39:39 by fmadura           #+#    #+#             */
/*   Updated: 2018/03/05 13:22:07 by fmadura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define ABS(x) (x < 0 ? -x : x)
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>
# include <wchar.h>

char			*ft_strsubin(char *out, char **in, char c);
char			**ft_strcut(char const *str, char c);
char			*ft_chartostr(char c);
char			*ft_strins(char *from, char *ins, size_t index);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strdup(const char *s);
char			*ft_strdup2(const char *s);
wchar_t			*ft_wstrdup(const wchar_t *s);
char			*ft_strdupcat(const char *s1, const char *s2);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *restrict s1, const char *restrict s2,
				size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);
size_t			ft_strlcat(char *restrict dst, const char *restrict src,
				size_t size);
size_t			ft_strlen(const char *str);
size_t			ft_wcslen(const wchar_t *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);

char			*ft_strtrim(char const *s);

char			*ft_strdjoin(char *s1, char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strljoin(char *s1, char *s2);
char			*ft_strrjoin(char *s1, char *s2);

char			*ft_utoa(unsigned int n);
char			*ft_ultoa(unsigned long n);
char			*ft_ulltoa(unsigned long long n);
char			*ft_itoa(int n);
char			*ft_ltoa(long n);
char			*ft_lltoa(long long n);
char			*ft_itoabase(int n, int base, char *basefrom);
char			*ft_ltoabase(long n, int base, char *bfrm);
char			*ft_lltoabase(long long n, int base, char *bfrm);
char			*ft_utoabase(unsigned int n, int base, char *bfrm);
char			*ft_ultoabase(unsigned long n, int base, char *bfrm);
char			*ft_ulltoabase(unsigned long long n, int base, char *bfrm);
int				ft_atoi(const char *str);

int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(char c);
int				ft_isxdigit(int c);
int				ft_isupper(int c);
int				ft_islower(int c);

int				ft_strchri(char *str, char c);
int				ft_strnchri(char *str, char c, int n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strcount_if(char *s, int (f)(int));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strnequ(char const *s1, char const *s2, size_t n);

int				ft_tolower(int c);
int				ft_toupper(int c);
void			ft_capitalize(char *s);
void			ft_lowercase(char *s);
char			*ft_strset(char *str, char c, size_t size);

void			ft_bzero(void *s, size_t n);
void			*ft_memalloc(size_t size);
void			*ft_memccpy(void *restrict dst, const void *restrict src,
				int c, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *restrict dst, const void *restrict src,
				size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_memdel(void **ap);
int				ft_memcmp(const void *s1, const void *s2, size_t n);

int				ft_putchar(char c);
int				ft_putwchar(wchar_t c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr(int nb);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char *str);
void			ft_putstr_fd(char const *s, int fd);

void			ft_strclr(char *s);
void			ft_strdel(char **as);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));

unsigned int	ft_pow(int num, int pow);
int				ft_abs(int c);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
int				ft_listsize(t_list **alst);
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstpush(t_list **alst, t_list *new);
#endif
