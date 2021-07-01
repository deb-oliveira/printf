/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_specf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:15:15 by doliveira         #+#    #+#             */
/*   Updated: 2021/07/01 17:00:00 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_zeroflag(const char *str, t_specf specf, t_print *print)
{
	if ((*str == 'd' || *str == 'i' || *str == 'o' || *str == 'e'
			|| *str == 'u' || *str == 'x' || *str == 'X' || *str == 'f'
			|| *str == 'g'))
	{
		while (print->len < (size_t)specf.width)
		{
			if ((*str == 'g' || *str == 'f' || *str == 'e' || *str == 'd' || *str == 'i')
				&& *(print->str) == '-')
			{
				ft_putstr_fd("-", 1);
				(print->str)++;
			}
			ft_putstr_fd("0", 1);
			(print->len)++;
		}
	}
	else if (*str == '%')
	{
		while (print->len < (size_t)specf.width)
		{
			ft_putstr_fd("0", 1);
			(print->len)++;
		}
	}
}

static void	ft_hashflag(const char *str, t_specf specf, t_print *print)
{
	char	*print_aux;

	if (specf.flags->hash == 0)
		return ;
	if ((*str == 'o' || *str == 'x' || *str == 'X') && *(print->str) != '0')
	{
		ft_putstr_fd("0", 1);
		if (*str == 'x' || *str == 'X')
			ft_putchar_fd(*str, 1);
	}
	else if ((*str == 'g' || *str == 'e' || *str == 'f') && !ft_strchr(print->str, '.'))
	{
		print_aux = print->str;
		print->str = ft_strmjoin(print->str, ".", ft_strclen(print->str, 'e'));
		free(print_aux);
	}
}

static void	ft_precision(const char *str, t_specf specf, t_print *print)
{
	size_t	print_len;

	if (specf.precision < 0)
		return ;
	if ((*str == 'g' && specf.flags->hash == 1) || 
		*str == 'd' || *str == 'i' || *str == 'o' || *str == 'e'
		|| *str == 'u' || *str == 'x' || *str == 'X' || *str == 'f')
	{
		if (*str != 'f' && *str != 'e' && *str != 'g')
			print_len = ft_strxlen(print->str, '-');
		else if (*str == 'e' || (*str == 'g' && ft_strchr(print->str, 'e')))
			print_len = ft_strclenc(print->str, '.', 'e') - 1;
		else
			print_len = ft_strsublen(print->str, '.');
		while (print_len < (size_t)specf.precision)
		{
			if ((*str == 'd' || *str == 'i') && *(print->str) == '-')
			{
				ft_putstr_fd("-", 1);
				(print->str)++;
			}
			ft_putstr_fd("0", 1);
			print_len++;
		}
		if (specf.precision == 0 && *(print->str) == '0' && print_len == 1)
			*(print->str) = '\0';
	}
	else if (*str == 's' && ft_strlen(print->str) > (size_t)specf.precision)
		(print->str)[specf.precision] = '\0';
}

static void	ft_width(const char *str, t_specf specf, t_print *print)
{
	if (specf.flags->zero == 0)
	{
		while (print->len < (size_t)specf.width)
		{
			ft_putstr_fd(" ", 1);
			(print->len)++;
		}
	}
	else
		ft_zeroflag(str, specf, print);
}

static char	*ft_xputcstr_fd(char *s, char c, int fd)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
	{
		write(fd, s, 1);
		s++;
	}
	if (*s == c)
		s++;
	return (s);
}

void	do_specf(const char *str, t_specf specf, t_print *print)
{

	ft_bytestoprint(str, specf, print);
	if (specf.flags->minus == 0)
		ft_width(str, specf, print);
	ft_hashflag(str, specf, print);
	if (*str != 'f' && *str != 'e' && *str != 'g')
		ft_precision(str, specf, print);
	if (*str == 'c')
		ft_putchar_fd(*(print->str), 1);
	else if (*str == 'e' || (*str == 'g' && ft_strchr(print->str, 'e')))
		ft_xputcstr_fd(print->str, 'e', 1);	
	else
		ft_putstr_fd(print->str, 1);
	if ((*str == 'f' || (*str == 'g' && !ft_strchr(print->str, 'e'))) 
		&& (ft_isdigit(*(print->str)) 
		|| (*(print->str) == '-' && ft_isdigit((print->str)[1]))))
		ft_precision(str, specf, print);
	else if (*str == 'e' || (*str == 'g' && ft_strchr(print->str, 'e')))
	{
		ft_precision(str, specf, print);
		ft_putstr_fd(ft_strchr(print->str, 'e'), 1);
	}
	if (specf.flags->minus == 1)
		ft_width(str, specf, print);
	free(print->str);
}
