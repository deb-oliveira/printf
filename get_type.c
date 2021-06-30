/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:32:08 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/30 14:35:01 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	get_numtype(const char *str, char **print, va_list *arg)
{
	if (*str == 'd' || *str == 'i')
		*print = ft_itoa_base(va_arg(*arg, int), "0123456789");
	else if (*str == 'u')
		*print = ft_utoa_base(va_arg(*arg, unsigned int), "0123456789");
	else if (*str == 'x')
		*print = ft_utoa_base(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (*str == 'X')
		*print = ft_utoa_base(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	else if (*str == 'o')
		*print = ft_utoa_base(va_arg(*arg, unsigned int), "01234567");
}

static void	get_strtype(const char *str, char **print, va_list *arg)
{
	if (*str == 's')
	{
		*print = va_arg(*arg, char *);
		if (*print == NULL)
			*print = ft_strdup("(null)");
		else
			*print = ft_strdup(*print);
	}
	else if (*str == 'c')
	{
		*print = ft_calloc(2, sizeof(char));
		(*print)[0] = va_arg(*arg, int);
	}
}

static void	get_ptrtype(char *str, char **print, t_specf specf, va_list *arg)
{
	char	*print_aux;

	if (*str == 'p')
	{
		*print = ft_uptrtoa_base(va_arg(*arg, uintptr_t), "0123456789abcdef");
		print_aux = *print;
		if (specf.precision == 0 && **print == '0')
			*print = ft_strdup("0x");
		else
			*print = ft_strjoin("0x", *print);
		free(print_aux);
	}
	else if (*str == '%')
	{
		*print = ft_calloc(2, sizeof(char));
		(*print)[0] = '%';
	}
}

static void	get_floattype(char *str, char **print, t_specf *specf, va_list *arg)
{
	if (*str == 'f')
	{
		if (specf->precision < 0)
			specf->precision = 6;
		*print = ft_ftoa_base(va_arg(*arg, double), specf->precision, "0123456789");
		if (!ft_isdigit(**print) && (**print != '-' || (**print == '-' && !ft_isdigit((*print)[1]))))
			specf->flags->zero = 0;
		else if (specf->precision == 0)
			(*print)[ft_strchr(*print, '.') - *print] = '\0';

	}
	if (*str == 'e')
	{
		if (specf->precision < 0)
			specf->precision = 6;
		*print = ft_etoa_base(va_arg(*arg, double), specf->precision, "0123456789");
		if (!ft_isdigit(**print) && (**print != '-' || (**print == '-' && !ft_isdigit((*print)[1]))))
			specf->flags->zero = 0;
	}
}

void	get_type(char *str, char **print, t_specf *specf, va_list *arg)
{
	get_numtype(str, print, arg);
	get_strtype(str, print, arg);
	get_ptrtype(str, print, *specf, arg);
	get_floattype(str, print, specf, arg);
}
