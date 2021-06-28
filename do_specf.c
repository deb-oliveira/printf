/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_specf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:15:15 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/28 10:29:22 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_zeroflag(const char *str_cpy, t_specf specf, t_print *print)
{
	if (specf.precision < 0
		&& (*str_cpy == 'd' || *str_cpy == 'i' || *str_cpy == 'o'
			|| *str_cpy == 'u' || *str_cpy == 'x' || *str_cpy == 'X'))
	{
		while (print->len < (size_t)specf.width)
		{
			if ((*str_cpy == 'd' || *str_cpy == 'i') && *(print->str) == '-')
			{
				ft_putstr_fd("-", 1);
				(print->str)++;
			}
			ft_putstr_fd("0", 1);
			(print->len)++;
		}
	}
	else if (*str_cpy == '%')
	{
		while (print->len < (size_t)specf.width)
		{
			ft_putstr_fd("0", 1);
			(print->len)++;
		}
	}
}

static void	ft_hashflag(const char *str_cpy, t_specf specf, size_t *count)
{
	if (specf.flags->hash == 0)
		return ;
	if (*str_cpy == 'o' || *str_cpy == 'x' || *str_cpy == 'X')
	{
		ft_putstr_fd("0", 1);
		if (*str_cpy == 'x' || *str_cpy == 'X')
		{
			ft_putchar_fd(*str_cpy, 1);
			(*count)++;
		}
		(*count)++;
	}
}

static void	ft_precision(const char *str_cpy, int precision, t_print *print)
{
	size_t	print_len;

	if (precision < 0
		|| *str_cpy == 'c' || *str_cpy == 'p' || *str_cpy == '%')
		return ;
	if (*str_cpy == 'd' || *str_cpy == 'i' || *str_cpy == 'o'
		|| *str_cpy == 'u' || *str_cpy == 'x' || *str_cpy == 'X')
	{
		print_len = ft_strxlen(print->str, '-');
		while (print_len < (size_t)precision)
		{
			if ((*str_cpy == 'd' || *str_cpy == 'i') && *(print->str) == '-')
			{
				ft_putstr_fd("-", 1);
				(print->str)++;
			}
			ft_putstr_fd("0", 1);
			print_len++;
		}
		if (precision == 0 && *(print->str) == '0' && print_len == 1)
			*(print->str) = '\0';
	}
	else if (*str_cpy == 's' &&  ft_strlen(print->str) > (size_t)precision)
		(print->str)[precision] = '\0';
}

static void	ft_width(const char *str_cpy, t_specf specf, t_print *print)
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
		ft_zeroflag(str_cpy, specf, print);
}

void	do_specf(const char *str_cpy, t_specf specf, t_print *print)
{
	char	*print_aux;

	print_aux = print->str;
	if (specf.precision >= 0 && 
		*str_cpy == 's' && (size_t)specf.precision < ft_strlen(print->str))
		print->len = specf.precision;
	else if ((*str_cpy == 'd' || *str_cpy == 'i' || *str_cpy == 'o'
		|| *str_cpy == 'u' || *str_cpy == 'x' || *str_cpy == 'X') &&
		(specf.precision == 0 && *(print->str) == '0' && ft_strlen(print->str) == 1))
		print->len = 0;
	else if (specf.precision >= 0 && (*str_cpy == 'd' || *str_cpy == 'i' || *str_cpy == 'o'
		|| *str_cpy == 'u' || *str_cpy == 'x' || *str_cpy == 'X')
		&& (size_t)specf.precision >= ft_strlen(print->str))
			print->len = specf.precision + (*(print->str) == '-');
	else if (*str_cpy == 'c')
		print->len = 1;
	else
		print->len = ft_strlen(print->str);
	if (specf.flags->minus == 0)
		ft_width(str_cpy, specf, print);
	ft_hashflag(str_cpy, specf, &(print->len));
	ft_precision(str_cpy, specf.precision, print);
	if (*str_cpy == 'c')
		ft_putchar_fd(*(print->str), 1);
	else
		ft_putstr_fd(print->str, 1);
	if (specf.flags->minus == 1)
		ft_width(str_cpy, specf, print);
	free(print_aux);
}
