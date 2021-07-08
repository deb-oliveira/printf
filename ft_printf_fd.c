/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 14:11:09 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 14:12:02 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printf_fd(const char *s, int fd, ...)
{
	t_print	str;
	t_print	print;
	t_specf	specf;
	va_list	arg;

	va_start(arg, fd);
	str.bytprint = 0;
	str.content = ft_nputcstr_fd((char *)s, '%', fd, &str.bytprint);
	while (*(str.content))
	{
		get_specf(&str.content, &specf, &arg);
		get_type(str, &(print.content), &specf, &arg);
		do_specf_and_print(str.content, specf, &print, fd);
		str.bytprint += print.bytprint;
		free(specf.flags);
		free(specf.lenght);
		str.content = ft_nputcstr_fd((str.content + 1), '%', fd, &str.bytprint);
	}
	va_end(arg);
	return (str.bytprint);
}
