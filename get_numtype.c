/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numtype.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:15:58 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/06 17:16:57 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	get_dtype(char *str, char **print, t_specf specf, va_list *arg)
{
	char	*base;

	base = ft_strdup("0123456789");
	if (*str == 'd' || *str == 'i')
	{
		if (specf.lenght->hh == 1)
			*print = ft_itoa_base((char)va_arg(*arg, int), base);
		else if (specf.lenght->h == 1)
			*print = ft_itoa_base((short int)va_arg(*arg, int), base);
		else if (specf.lenght->l == 1)
			*print = ft_litoa_base(va_arg(*arg, long int), base);
		else if (specf.lenght->ll == 1)
			*print = ft_llitoa_base(va_arg(*arg, long long int), base);
		else
			*print = ft_itoa_base(va_arg(*arg, int), base);
	}
	free(base);
}

void	get_utype(char *str, char **print, t_specf specf, va_list *arg)
{
	char	*base;

	base = ft_strdup("0123456789");
	if (*str == 'u')
	{
		if (specf.lenght->hh == 1)
			*print = ft_utoa_base((__u_char)va_arg(*arg, unsigned int), base);
		else if (specf.lenght->h == 1)
			*print = ft_utoa_base((__u_short)va_arg(*arg, unsigned int), base);
		else if (specf.lenght->l == 1)
			*print = ft_lutoa_base(va_arg(*arg, long unsigned int), base);
		else if (specf.lenght->ll == 1)
			*print = ft_llutoa_base(va_arg(*arg, long long unsigned int), base);
		else
			*print = ft_utoa_base(va_arg(*arg, unsigned int), base);
	}
	free(base);
}

void	get_xtype(char *str, char **print, t_specf specf, va_list *arg)
{
	char	*base;

	base = ft_strdup("0123456789abcdef");
	if (*str == 'x')
	{
		if (specf.lenght->hh == 1)
			*print = ft_utoa_base((__u_char)va_arg(*arg, unsigned int), base);
		else if (specf.lenght->h == 1)
			*print = ft_utoa_base((__u_short)va_arg(*arg, unsigned int), base);
		else if (specf.lenght->l == 1)
			*print = ft_lutoa_base(va_arg(*arg, long unsigned int), base);
		else if (specf.lenght->ll == 1)
			*print = ft_llutoa_base(va_arg(*arg, long long unsigned int), base);
		else
			*print = ft_utoa_base(va_arg(*arg, unsigned int), base);
	}
	free(base);
}

void	get_Xtype(char *str, char **print, t_specf specf, va_list *arg)
{
	char	*base;

	base = ft_strdup("0123456789ABCDEF");
	if (*str == 'X')
	{
		if (specf.lenght->hh == 1)
			*print = ft_utoa_base((__u_char)va_arg(*arg, unsigned int), base);
		else if (specf.lenght->h == 1)
			*print = ft_utoa_base((__u_short)va_arg(*arg, unsigned int), base);
		else if (specf.lenght->l == 1)
			*print = ft_lutoa_base(va_arg(*arg, long unsigned int), base);
		else if (specf.lenght->ll == 1)
			*print = ft_llutoa_base(va_arg(*arg, long long unsigned int), base);
		else
			*print = ft_utoa_base(va_arg(*arg, unsigned int), base);
	}
	free(base);
}

void	get_otype(char *str, char **print, t_specf specf, va_list *arg)
{
	char	*base;

	base = ft_strdup("01234567");
	if (*str == 'o')
	{
		if (specf.lenght->hh == 1)
			*print = ft_utoa_base((__u_char)va_arg(*arg, unsigned int), base);
		else if (specf.lenght->h == 1)
			*print = ft_utoa_base((__u_short)va_arg(*arg, unsigned int), base);
		else if (specf.lenght->l == 1)
			*print = ft_lutoa_base(va_arg(*arg, long unsigned int), base);
		else if (specf.lenght->ll == 1)
			*print = ft_llutoa_base(va_arg(*arg, long long unsigned int), base);
		else
			*print = ft_utoa_base(va_arg(*arg, unsigned int), base);
	}
	free(base);
}
