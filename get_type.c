/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:32:08 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 09:03:21 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	get_ntype(t_print str, char **print, t_specf specf, va_list *arg)
{
	if (*(str.content) == 'n')
	{
		if (specf.lenght->hh == 1)
			*((char *)va_arg(*arg, int *)) = str.bytprint;
		else if (specf.lenght->h == 1)
			*((short int *)va_arg(*arg, int *)) = str.bytprint;
		else if (specf.lenght->l == 1)
			*(va_arg(*arg, long int *)) = str.bytprint;
		else if (specf.lenght->ll == 1)
			*(va_arg(*arg, long long int *)) = str.bytprint;
		else
			*(va_arg(*arg, int *)) = str.bytprint;
		*print = ft_strdup("");
	}
}

static void	get_scptype(char *str, char **print, t_specf specf, va_list *arg)
{
	char	*print_aux;

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
	if (*str == 'p')
	{
		*print = ft_uptrtoa_base(va_arg(*arg, uintptr_t), "0123456789abcdef");
		print_aux = *print;
		if (specf.precision == 0 && ft_strcmp(*print, "0") == 0)
			*print = ft_strdup("0x");
		else
			*print = ft_strjoin("0x", *print);
		free(print_aux);
	}
}

static void	get_percent(char *str, char **print)
{
	if (*str == '%')
	{
		*print = ft_calloc(2, sizeof(char));
		(*print)[0] = '%';
	}
}

static void	get_floattype(char *str, char **print, t_specf *specf, va_list *arg)
{
	if ((*str == 'e' || *str == 'f' || *str == 'g') && specf->precision < 0)
		specf->precision = 6;
	if (*str == 'f')
		*print = ft_ftoa((long double)va_arg(*arg, double), specf->precision);
	else if (*str == 'e')
		*print = ft_etoa((long double)va_arg(*arg, double), specf->precision);
	else if (*str == 'g')
	{
		specf->precision += (specf->precision == 0);
		*print = ft_gtoa((long double)va_arg(*arg, double), specf->precision);
	}
	if ((*str == 'f' || *str == 'e' || *str == 'g') && ((!ft_isdigit(**print)
				&& **print != '-') || ft_strcmp(*print, "-inf") == 0))
		specf->flags->zero = 0;
}

void	get_type(t_print str, char **print, t_specf *specf, va_list *arg)
{
	get_dtype(str.content, print, *specf, arg);
	get_utype(str.content, print, *specf, arg);
	get_xtype(str.content, print, *specf, arg);
	get_Xtype(str.content, print, *specf, arg);
	get_otype(str.content, print, *specf, arg);
	get_scptype(str.content, print, *specf, arg);
	get_ntype(str, print, *specf, arg);
	get_percent(str.content, print);
	get_floattype(str.content, print, specf, arg);
}
