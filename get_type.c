/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:32:08 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/14 12:36:34 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	get_numtype(const char *str_cpy, char **print, va_list *arg)
{
	if (*str_cpy == 'd' || *str_cpy == 'i')
		*print = ft_itoa_base(va_arg(*arg, int), "0123456789");
	else if (*str_cpy == 'u')
		*print = ft_utoa_base(va_arg(*arg, unsigned int), "0123456789");
	else if (*str_cpy == 'x')
		*print = ft_utoa_base(va_arg(*arg, unsigned int), "0123456789abcdef");
	else if (*str_cpy == 'X')
		*print = ft_utoa_base(va_arg(*arg, unsigned int), "0123456789ABCDEF");
	else if (*str_cpy == 'o')
		*print = ft_utoa_base(va_arg(*arg, unsigned int), "01234567");
}

static void	get_strtype(const char *str_cpy, char **print, va_list *arg)
{
	if (*str_cpy == 's')
	{
		*print = va_arg(*arg, char *);
		if (*print == NULL)
			*print = ft_strdup("(null)");
		else
			*print = ft_strdup(*print);
	}
	else if (*str_cpy == 'c')
	{
		*print = ft_calloc(2, sizeof(char));
		(*print)[0] = va_arg(*arg, int);
	}
}

static void	get_ptrtype(const char *str_cpy, char **print, va_list *arg)
{
	char	*print_aux;

	if (*str_cpy == 'p')
	{
		*print = ft_uptrtoa_base(va_arg(*arg, uintptr_t), "0123456789abcdef");
		print_aux = *print;
		*print = ft_strjoin("0x", *print);
		free(print_aux);
	}
	else if (*str_cpy == '%')
	{
		*print = ft_calloc(2, sizeof(char));
		(*print)[0] = '%';
	}
}

void	get_type(const char *str_cpy, char **print, va_list *arg)
{
	get_numtype(str_cpy, print, arg);
	get_strtype(str_cpy, print, arg);
	get_ptrtype(str_cpy, print, arg);
}
