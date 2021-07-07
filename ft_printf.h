/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:37:05 by doliveira         #+#    #+#             */
/*   Updated: 2021/07/06 18:07:49 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
//# include <string.h>
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

typedef struct s_lenght
{
	bool	hh;
	bool	h;
	bool	l;
	bool	ll;
}				t_lenght;

typedef struct s_specf
{
	t_flags		*flags;
	int			width;
	int			precision;
	t_lenght	*lenght;
}				t_specf;

typedef struct s_print
{
	char	*content;
	size_t	bytprint;
}				t_print;

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

void	ft_strrev(char **str);

char	*ft_utoa_base(unsigned int nbr, char *base);

char	*ft_itoa_base(int nbr, char *base);

int		ft_printf(const char *str, ...);

char	*ft_nputcstr_fd(char *s, char c, int fd, size_t *n);

char	*ft_uptrtoa_base(uintptr_t nbr, char *base);

void	get_specf(char **str_cpy, t_specf *specf, va_list *arg);

void	get_type(t_print str, char **print, t_specf *specf, va_list *arg);

void	do_specf_and_print(const char *str_cpy, t_specf specf, t_print *print);

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

void	ft_bytestoprint(const char *str, t_specf specf, t_print *print);

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

void	get_otype(char *str, char **print, t_specf specf, va_list *arg);

void	get_Xtype(char *str, char **print, t_specf specf, va_list *arg);

void	get_xtype(char *str, char **print, t_specf specf, va_list *arg);

void	get_utype(char *str, char **print, t_specf specf, va_list *arg);

void	get_dtype(char *str, char **print, t_specf specf, va_list *arg);

void	ft_zeroflag(const char *str, t_specf specf, t_print *print);

void	ft_hashflag(const char *str, t_specf specf, char **print);

void	ft_signedflag(const char *str, t_specf specf, char **print);
#endif