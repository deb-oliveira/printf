/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:05:09 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/14 12:44:51 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	get_flags(char **str, t_specf *specf)
{
	specf->flags = ft_calloc(1, sizeof(t_flags));
	while (**str == '#' || **str == '0' || **str == '-'
		|| **str == ' ' || **str == '+' || **str == 39)
	{
		if (**str == '#')
			specf->flags->hash = 1;
		else if (**str == '0')
			specf->flags->zero = 1;
		else if (**str == '-')
			specf->flags->minus = 1;
		else if (**str == ' ')
			specf->flags->space = 1;
		else if (**str == '+')
			specf->flags->plus = 1;
		else if (**str == 39)
			specf->flags->apostr = 1;
		(*str)++;
	}
	if (specf->flags->zero == 1 && specf->flags->minus == 1)
		specf->flags->zero = 0;
	if (specf->flags->plus == 1 && specf->flags->space == 1)
		specf->flags->plus = 0;
}

static void	get_width(char **str_cpy, t_specf *specf, va_list *arg)
{
	specf->width = 0;
	if (ft_isdigit(**str_cpy))
	{
		specf->width = ft_atoi(*str_cpy);
		while (ft_isdigit(**str_cpy))
			(*str_cpy)++;
	}
	else if (**str_cpy == '*')
	{
		specf->width = va_arg((*arg), int);
		if (specf->width < 0)
		{
			specf->flags->minus = 1;
			specf->width = specf->width * (-1);
			if (specf->flags->zero == 1)
				specf->flags->zero = 0;
		}
		(*str_cpy)++;
	}
}

static void	get_precision(char **str_cpy, t_specf *specf, va_list *arg)
{
	specf->precision = -1;
	if (**str_cpy != '.')
		return ;
	(*str_cpy)++;
	if (**str_cpy == '*')
	{
		specf->precision = va_arg(*arg, int);
		(*str_cpy)++;
	}
	else
	{
		specf->precision = ft_atoi(*str_cpy);
		while (ft_isdigit(**str_cpy))
			(*str_cpy)++;
	}
	if (specf->flags->zero == 1 && specf->precision > -1 && **str_cpy != '%')
		specf->flags->zero = 0;
}

void	get_specf(char **str_cpy, t_specf *specf, va_list *arg)
{
	get_flags(str_cpy, specf);
	get_width(str_cpy, specf, arg);
	get_precision(str_cpy, specf, arg);
}
