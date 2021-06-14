/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:59:47 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/13 23:07:38 by doliveira        ###   ########.fr       */
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
	char	*print_aux;

	if (*str_cpy == 's')
		*print = strdup(va_arg(*arg, char *));
	else if (*str_cpy == 'c')
	{
		*print = ft_calloc(2, sizeof(char));
		(*print)[0] = va_arg(*arg, int);
	}
	else if (*str_cpy == 'p')
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

int	ft_printf(const char *str, ...)
{
	char	*str_cpy;
	char	*print;
	t_specf	specf;
	va_list	arg;
	int		count;

	va_start(arg, str);
	count = 0;
	str_cpy = ft_putcstr_fd((char *)str, '%', 1, &count);
	while (*str_cpy)
	{
		str_cpy++;
		get_specf(&str_cpy, &specf, &arg);
		get_numtype(str_cpy, &print, &arg);
		get_strtype(str_cpy, &print, &arg);
		do_specf(str_cpy, specf, &print);
		ft_putstr_fd(print, 1);
		count += ft_strlen(print);
		free(print);
		free(specf.flags);
		str_cpy = ft_putcstr_fd((char *)(str_cpy + 1), '%', 1, &count);
	}	
	va_end(arg);
	return (count);
}
