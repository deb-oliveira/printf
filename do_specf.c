/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_specf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:15:15 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/13 23:41:08 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_precision(const char *str_cpy, int precision, char **print)
{
	char	*print_aux;

	if (precision < 0)
		return ;
	if (*str_cpy == 'd' || *str_cpy == 'i' || *str_cpy == 'o'
		|| *str_cpy == 'u' || *str_cpy == 'x' || *str_cpy == 'X')
	{
		while (strlen(*print) < (size_t)precision)
		{
			print_aux = *print;
			*print = ft_strjoin("0", *print);
			free(print_aux);
		}
		if (precision == 0 && **print == '0' && strlen(*print) == 1)
			**print = '\0';
	}
	else if (*str_cpy == 's' && strlen(*print) > (size_t)precision)
	{
		print_aux = *print;
		*print = ft_substr(*print, 0, precision);
		free(print_aux);
	}
}

static void	ft_width(const char *str_cpy, t_specf specf, char **print)
{
	char	*print_aux;
	
	while (strlen(*print) < (size_t)(specf.width))
	{
		print_aux = *print;
		if (specf.flags->zero == 1 && specf.flags->hash == 1
			&& (*str_cpy == 'o' || *str_cpy == 'x' || *str_cpy == 'X'))
			*print = ft_strjoin("0", *print);
		else if (specf.flags->zero == 1 && *str_cpy != 's' && *str_cpy != 'p'
			&& *str_cpy != 'c' && *str_cpy != '%' && specf.precision < 0)
			*print = ft_strjoin("0", *print);
		else if (specf.flags->zero == 1 && *str_cpy == '%')
			*print = ft_strjoin("0", *print);
		else if (specf.flags->minus == 1)
			*print = ft_strjoin(*print, " ");
		else
			*print = ft_strjoin(" ", *print);
		free(print_aux);
	}
}

static void	ft_hashflag(const char *str_cpy, t_specf specf, char **print)
{
	char	*print_aux;

	if (specf.flags->hash == 1)
	{
		print_aux = *print;
		if (*str_cpy == 'o')
			*print = ft_strjoin("0", *print);
		if (*str_cpy == 'x')
			*print = ft_strjoin("0x", *print);
		if (*str_cpy == 'X')
			*print = ft_strjoin("0X", *print);
		free(print_aux);
	}
}

void	do_specf(const char *str_cpy, t_specf specf, char **print)
{
	ft_precision(str_cpy, specf.precision, print);
	ft_hashflag(str_cpy, specf, print);
	ft_width(str_cpy, specf, print);
}
