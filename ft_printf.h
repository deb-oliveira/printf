/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:37:05 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/15 10:10:29 by doliveira        ###   ########.fr       */
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

char	*ft_strrev(char *str);

char	*ft_utoa_base(unsigned int nbr, char *base);

char	*ft_itoa_base(int nbr, char *base);

int		ft_printf(const char *str, ...);

char	*ft_putcstr_fd(char *s, char c, int fd, int *n);

char	*ft_uptrtoa_base(uintptr_t nbr, char *base);

void	get_specf(char **str_cpy, t_specf *specf, va_list *arg);

void	get_type(const char *str_cpy, char **print, va_list *arg);

void	do_specf(const char *str_cpy, t_specf specf, char **print);

char	*ft_strmjoin(char const *s1, char const *s2, int start);

void	ft_putmem_fd(const char *s, int n, int fd);

char	*ft_memjoin(const char *s1, const char *s2, size_t size1, size_t size2);

int		ft_max(int a, int b);

#endif