/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:23:36 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 14:02:05 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void	ft_zeroflag(const char *str, t_specf specf, t_print *print, int fd)
{
	if ((*str != 's' || *str != 'c' || *str != 'p'
			|| *str != 'n' || *str == '%'))
	{
		while (print->bytprint < (size_t)specf.width)
		{
			if ((*str == 'g' || *str == 'f' || *str == 'e'
					|| *str == 'd' || *str == 'i')
				&& (*(print->content) == '-' || *(print->content) == ' '
					|| *(print->content) == '+'))
			{
				ft_putchar_fd(*(print->content), fd);
				(print->content)++;
			}
			ft_putstr_fd("0", fd);
			(print->bytprint)++;
		}
	}
	else if (*str == '%')
	{
		while (print->bytprint < (size_t)specf.width)
		{
			ft_putstr_fd("0", fd);
			(print->bytprint)++;
		}
	}
}

void	ft_hashflag(const char *str, t_specf specf, char **print, int fd)
{
	char	*print_aux;

	if (specf.flags->hash == 0)
		return ;
	if ((*str == 'o' || *str == 'x' || *str == 'X') && **print != '0')
	{
		ft_putstr_fd("0", fd);
		if (*str == 'x' || *str == 'X')
			ft_putchar_fd(*str, fd);
	}
	else if ((*str == 'g' || *str == 'e' || *str == 'f')
		&& !ft_strchr(*print, '.'))
	{
		print_aux = *print;
		*print = ft_strmjoin(*print, ".", ft_strclen(*print, 'e'));
		free(print_aux);
	}
}

void	ft_signedflag(const char *str, t_specf specf, char **print)
{
	if (specf.flags->space == 0 && specf.flags->plus == 0)
		return ;
	if (**print != '-' && (*str == 'd' || *str == 'i'
			|| *str == 'g' || *str == 'f' || *str == 'e' )
		&& ft_isdigit(**print))
	{
		if (specf.flags->space == 1)
			*print = ft_ftfree(3, &ft_strjoin, ft_strdup(" "), *print);
		else
			*print = ft_ftfree(3, &ft_strjoin, ft_strdup("+"), *print);
	}
}
