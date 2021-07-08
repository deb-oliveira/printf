/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:55:03 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 09:12:58 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_functions
{
	char	*(*f3arg)(char *s1, char *s2, char *s3);
	char	*(*f2arg)(char *s1, char *s2);
	char	*(*f1arg)(char *s1);
}				t_functions;

typedef union u_fbits
{
	double		f;
	uint64_t	u;
}			t_fbits;

void	ft_bzero(void *str, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memchr(const void *str, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

size_t	ft_strlen(char const *str);

size_t	ft_strlcpy(char *dest, char const *src, size_t size);

size_t	ft_strlcat(char *dest, char const *src, size_t size);

char	*ft_strchr(const char *str, int c);

char	*ft_strrchr(const char *str, int c);

char	*ft_strnstr(const char *str, const char *to_find, size_t len);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

int		ft_atoi(const char *str);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strdup(char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_strctrim(char const *s1, char c);

char	**ft_split(char const *s, char c);

int		ft_iterative_power(int nb, int power);

char	*ft_itoa(int n);

int		ft_signal(int n);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void*));

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

t_list	*ft_lstnew(void *content);

int		ft_lstsize(t_list *lst);

int		ft_isspace(char c);

void	ft_strrev(char **str);

char	*ft_utoa_base(unsigned int nbr, char *base);

char	*ft_itoa_base(int nbr, char *base);

char	*ft_nputcstr_fd(char *s, char c, int fd, size_t *n);

char	*ft_uptrtoa_base(uintptr_t nbr, char *base);

char	*ft_strmjoin(char const *s1, char const *s2, int start);

void	ft_putmem_fd(const char *s, int n, int fd);

char	*ft_memjoin(const char *s1, const char *s2, size_t size1, size_t size2);

int		ft_max(int a, int b);

float	ft_fpower(float nb, int power);

int		ft_strcmp(const char *str1, const char *str2);

char	*ft_u128toa_base(__uint128_t nbr, char *base);

char	*ft_upointtoa_base(long double nbr, char *base, size_t precision);

char	*ft_strcjoin(char const *s1, char c);

char	*ft_ftoa(long double f, int n);

char	*ft_strxdup(char *src, char x);

size_t	ft_strxlen(char *src, char x);

int		ft_min(int a, int b);

size_t	ft_cstrlen(const char *str, char c);

char	*ft_str3join(char const *s1, char const *s2, char const *s3);

char	*ft_etoa(long double f, int n);

size_t	ft_strclen(const char *str, char c);

size_t	ft_strclenc(const char *str, char c1, char c2);

void	ft_swap(char *a, char *b);

char	*ft_gtoa(long double f, int n);

char	*ft_lutoa_base(long unsigned int nbr, char *base);

char	*ft_llutoa_base(long long unsigned int nbr, char *base);

char	*ft_litoa_base(long int nbr, char *base);

char	*ft_llitoa_base(long long int nbr, char *base);

char	*ft_ftfree(int n, ...);

char	*ft_putcstr_fd(char *s, char c, int fd);

#endif