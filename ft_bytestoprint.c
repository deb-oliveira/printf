/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bytestoprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:55:29 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 09:02:36 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_bytes4flags(const char *str, t_specf specf, t_print *print)
{
	if (specf.flags->hash == 1)
	{
		if (*(print->content) != '0')
			print->bytprint += 2 * (*str == 'x' || *str == 'X') + (*str == 'o');
		if ((*str == 'g' || *str == 'e' || *str == 'f')
			&& !ft_strchr(print->content, '.'))
			print->bytprint += 1;
	}
	if (specf.flags->space == 1 || specf.flags->plus == 1)
	{
		if (*(print->content) != '-' && (*str == 'd' || *str == 'i'
				|| *str == 'g' || *str == 'f' || *str == 'e' )
			&& ft_isdigit(*(print->content)))
			print->bytprint += 1;
	}	
}

static void	ft_bytes4floats(const char *str, t_specf specf, t_print *print)
{
	if (*str == 'f')
		print->bytprint = specf.precision + ft_strclen(print->content, '.')
			+ 1 * (specf.precision > 0);
	else if (*str == 'e')
		print->bytprint = specf.precision + 5
			+ 1 * (*(print->content) == '-')
			+ 1 * (specf.precision > 0);
	else if (specf.flags->hash == 1 && *str == 'g')
		print->bytprint = specf.precision
			+ 4 * (ft_strchr(print->content, 'e') != NULL)
			+ (ft_strncmp(print->content, "0.", 2) == 0
				|| ft_strncmp(print->content, "-0.", 3) == 0)
			+ 1 * (*(print->content) == '-')
			+ 1 * (ft_strchr(print->content, '.') != NULL);
}

void	ft_bytestoprint(const char *str, t_specf specf, t_print *print)
{
	bool	isexception;
	bool	isnumtype;

	isnumtype = (*str == 'd' || *str == 'i' || *str == 'o'
			|| *str == 'u' || *str == 'x' || *str == 'X');
	isexception = ((!ft_isdigit(*(print->content)) && *(print->content) != '-')
			|| ft_strcmp(print->content, "-inf") == 0);
	if (specf.precision >= 0 && *str == 's'
		&& (size_t)specf.precision < ft_strlen(print->content))
		print->bytprint = specf.precision;
	else if (specf.precision >= 0 && isnumtype
		&& (size_t)specf.precision >= ft_strlen(print->content))
		print->bytprint = specf.precision + (*(print->content) == '-');
	else if (specf.precision == 0 && isnumtype && *(print->content) == '0'
		&& ft_strlen(print->content) == 1)
		print->bytprint = 0;
	else if (*str == 'c')
		print->bytprint = 1;
	else if ((*str == 'f' || *str == 'e'
			|| (*str == 'g' && specf.flags->hash == 1)) && !isexception)
		ft_bytes4floats(str, specf, print);
	else
		print->bytprint = ft_strlen(print->content);
	ft_bytes4flags(str, specf, print);
}
