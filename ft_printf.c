/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:59:47 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/15 14:35:56 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	do_print(char *str_cpy, char **print, t_specf *specf, int fd)
{
	if (*str_cpy != 'c')
		ft_putstr_fd(*print, 1);
	else if (specf->width > 1)
		ft_putmem_fd(*print, specf->width, fd);
	else
		ft_putmem_fd(*print, 1, fd);
	free(*print);
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
		if (*str_cpy == 'n')
			*(va_arg(arg, int *)) = count;
		else
		{
			get_type(str_cpy, &print, specf, &arg);
			do_specf(str_cpy, specf, &print);
			if (*str_cpy != 'c')
				count += ft_strlen(print);
			else
				count += ft_max(1, specf.width);
			do_print(str_cpy, &print, &specf, 1);
		}
		free(specf.flags);
		str_cpy = ft_putcstr_fd((char *)(str_cpy + 1), '%', 1, &count);
	}
	va_end(arg);
	return (count);
}
