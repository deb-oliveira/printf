/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytestoprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:55:29 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/28 14:48:45 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	is_numtype(char *str)
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
	else if (specf.precision >= 0 && is_numtype
		&& (size_t)specf.precision >= ft_strlen(print->str))
		print->len = specf.precision + (*(print->str) == '-');
	else if (specf.precision == 0 && is_numtype && *(print->str) == '0'
		&& ft_strlen(print->str) == 1)
		print->len = 0;
	else if (*str == 'c')
		print->len = 1;
	else
		print->len = ft_strlen(print->str);
}
