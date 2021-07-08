/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:05:09 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 09:03:11 by dde-oliv         ###   ########.fr       */
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
		specf->flags->space = 0;
}

static void	get_width(char **str, t_specf *specf, va_list *arg)
{
	specf->width = 0;
	if (ft_isdigit(**str))
	{
		specf->width = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	else if (**str == '*')
	{
		specf->width = va_arg((*arg), int);
		if (specf->width < 0)
		{
			specf->flags->minus = 1;
			specf->width = specf->width * (-1);
			if (specf->flags->zero == 1)
				specf->flags->zero = 0;
		}
		(*str)++;
	}
}

static void	get_precision(char **str, t_specf *specf, va_list *arg)
{
	specf->precision = -1;
	if (**str != '.')
		return ;
	(*str)++;
	if (**str == '*')
	{
		specf->precision = va_arg(*arg, int);
		(*str)++;
	}
	else
	{
		specf->precision = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	if (specf->flags->zero == 1 && specf->precision > -1 && **str != '%'
		&& **str != 'g' && **str != 'f' && **str != 'e')
		specf->flags->zero = 0;
}

static void	get_lenght(char **str, t_specf *specf)
{
	specf->lenght = ft_calloc(1, sizeof(t_lenght));
	if (ft_strncmp(*str, "hh", 2) == 0)
		specf->lenght->hh = 1;
	else if (ft_strncmp(*str, "h", 1) == 0)
		specf->lenght->h = 1;
	else if (ft_strncmp(*str, "ll", 2) == 0)
		specf->lenght->ll = 1;
	else if (ft_strncmp(*str, "l", 1) == 0)
		specf->lenght->l = 1;
	if (specf->lenght->h == 1 || specf->lenght->l == 1)
		(*str)++;
	else if (specf->lenght->hh == 1 || specf->lenght->ll == 1)
		(*str) += 2;
}

void	get_specf(char **str, t_specf *specf, va_list *arg)
{
	get_flags(str, specf);
	get_width(str, specf, arg);
	get_precision(str, specf, arg);
	get_lenght(str, specf);
}
