/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:59:47 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/14 12:37:51 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

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
		get_type(str_cpy, &print, &arg);
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
