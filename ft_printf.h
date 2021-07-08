/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 12:37:05 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 14:13:46 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdint.h>
# include <stdlib.h>
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

int		ft_printf(const char *str, ...);

int		ft_printf_fd(const char *s, int fd, ...);

void	get_specf(char **str, t_specf *specf, va_list *arg);

void	get_type(t_print str, char **print, t_specf *specf, va_list *arg);

void	do_specf_and_print(char *str, t_specf specf, t_print *print, int fd);

void	ft_bytestoprint(const char *str, t_specf specf, t_print *print);

void	get_otype(char *str, char **print, t_specf specf, va_list *arg);

void	get_Xtype(char *str, char **print, t_specf specf, va_list *arg);

void	get_xtype(char *str, char **print, t_specf specf, va_list *arg);

void	get_utype(char *str, char **print, t_specf specf, va_list *arg);

void	get_dtype(char *str, char **print, t_specf specf, va_list *arg);

void	ft_zeroflag(const char *str, t_specf specf, t_print *print, int fd);

void	ft_hashflag(const char *str, t_specf specf, char **print, int fd);

void	ft_signedflag(const char *str, t_specf specf, char **print);

#endif