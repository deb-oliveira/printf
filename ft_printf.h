/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:37:05 by doliveira         #+#    #+#             */
/*   Updated: 2021/07/01 11:20:31 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdbool.h>

typedef struct s_flags
{
	bool	hash;
	bool	zero;
	bool	minus;
	bool	space;
	bool	plus;
	bool	apostr;
}				t_flags;

typedef struct s_specf
{
	t_flags	*flags;
	int		width;
	int		precision;
}				t_specf;

typedef struct s_print
{
	char	*str;
	size_t	len;
}				t_print;

typedef union u_fbits
{
	double		f;
	uint64_t	u;
}			t_fbits;

void	ft_strrev(char **str);

char	*ft_utoa_base(unsigned int nbr, char *base);

char	*ft_itoa_base(int nbr, char *base);

int		ft_printf(const char *str, ...);

char	*ft_putcstr_fd(char *s, char c, int fd, int *n);

char	*ft_uptrtoa_base(uintptr_t nbr, char *base);

void	get_specf(char **str_cpy, t_specf *specf, va_list *arg);

void	get_type(char *str, char **print, t_specf *specf, va_list *arg);

void	do_specf(const char *str_cpy, t_specf specf, t_print *print);

char	*ft_strmjoin(char const *s1, char const *s2, int start);

void	ft_putmem_fd(const char *s, int n, int fd);

char	*ft_memjoin(const char *s1, const char *s2, size_t size1, size_t size2);

int		ft_max(int a, int b);

float	ft_fpower(float nb, int power);

int		ft_strcmp(const char *str1, const char *str2);

char	*ft_u128toa_base(__uint128_t nbr, char *base);

char	*ft_upointtoa_base(long double nbr, char *base, size_t precision);

char	*ft_strcjoin(char const *s1, char c);

char	*ft_ftoa_base(long double f, int n, char *base);

char	*ft_strxdup(char *src, char x);

size_t	ft_strxlen(char *src, char x);

int		ft_min(int a, int b);

void	ft_bytestoprint(const char *str, t_specf specf, t_print *print);

size_t	ft_strsublen(const char *str, char c);

char	*ft_3strjoin(char const *s1, char const *s2, char const *s3);

char	*ft_etoa_base(long double f, int n, char *base);

size_t	ft_strclen(const char *str, char c);

size_t	ft_strclenc(const char *str, char c1, char c2);

void	ft_swap(char *a, char *b);

char	*ft_gtoa_base(long double f, int n, char *base);
#endif