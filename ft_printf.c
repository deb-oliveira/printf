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
	char	*str_cpy;
	t_print	print;
	t_specf	specf;
	va_list	arg;
	int		count;

	va_start(arg, str);
	count = 0;
	str_cpy = ft_putcstr_fd((char *)str, '%', 1, &count);
	while (*str_cpy)
	{
		get_specf(&str_cpy, &specf, &arg);
		if (*str_cpy == 'n')
			*(va_arg(arg, int *)) = count;
		else
		{
			get_type(str_cpy, &(print.str), &specf, &arg);
			do_specf(str_cpy, specf, &print);
			count += print.len;
		}
		free(specf.flags);
		str_cpy = ft_putcstr_fd((char *)(str_cpy + 1), '%', 1, &count);
	}
	va_end(arg);
	return (count);
}
