/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:59:47 by dde-oliv         #+#    #+#             */
/*   Updated: 2021/07/01 10:29:59 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf(const char *str, ...)
{
	t_print	str_cpy;
	t_print	print;
	t_specf	specf;
	va_list	arg;

	va_start(arg, str);
	str_cpy.len = 0;
	str_cpy.str = ft_putcstr_fd((char *)str, '%', 1, &str_cpy.len);
	while (*(str_cpy.str))
	{
		get_specf(&str_cpy.str, &specf, &arg);
		get_type(str_cpy, &(print.str), &specf, &arg);
		do_specf(str_cpy.str, specf, &print);
		str_cpy.len += print.len;
		free(specf.flags);
		free(specf.lenght);
		str_cpy.str = ft_putcstr_fd((str_cpy.str + 1), '%', 1, &str_cpy.len);
	}
	va_end(arg);
	return (str_cpy.len);
}
