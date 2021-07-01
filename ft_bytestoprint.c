/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytestoprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:55:29 by doliveira         #+#    #+#             */
/*   Updated: 2021/07/01 17:02:33 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	is_numtype(const char *str)
{
	if ((*str == 'd' || *str == 'i' || *str == 'o'
			|| *str == 'u' || *str == 'x' || *str == 'X'))
		return (1);
	return (0);
}

void	ft_bytestoprint(const char *str, t_specf specf, t_print *print)
{
	if (specf.precision >= 0 && *str == 's'
		&& (size_t)specf.precision < ft_strlen(print->str))
		print->len = specf.precision;
	else if (specf.precision >= 0 && is_numtype(str)
		&& (size_t)specf.precision >= ft_strlen(print->str))
		print->len = specf.precision + (*(print->str) == '-');
	else if (specf.precision > 0 && (*str == 'f' || (specf.flags->hash == 1 && *str == 'g' && !ft_strchr(print->str, 'e')))
		&& (ft_isdigit(*(print->str)) || ((print->str)[0] == '-' && ft_isdigit((print->str)[1]))))
		print->len = specf.precision
			+ (ft_strchr(print->str, '.') - print->str + 1);
	else if (specf.precision > 0 && (*str == 'e' || (specf.flags->hash == 1 && *str == 'g' && ft_strchr(print->str, 'e')))
		&& (ft_isdigit(*(print->str)) || ((print->str)[0] == '-' && ft_isdigit((print->str)[1]))))
		print->len = specf.precision + ft_strclen(print->str, '.') + 1
			+ ft_strclenc(print->str, 'e', '\0');
	else if (specf.precision == 0 && is_numtype(str) && *(print->str) == '0'
		&& ft_strlen(print->str) == 1)
		print->len = 0;
	else if (*str == 'c')
		print->len = 1;
	else
		print->len = ft_strlen(print->str);
	if (specf.flags->hash == 1)
	{
		if (*(print->str) != '0')
			print->len += 2 * (*str == 'x' || *str == 'X') + (*str == 'o');
		if ((*str == 'g' || *str == 'e' || *str == 'f') && !ft_strchr(print->str, '.'))
			print->len += 1;
	}
}
