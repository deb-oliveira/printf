/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_specf_and_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 21:15:15 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 14:06:34 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static void	ft_prec_len(const char *str, char **print, int *len)
{
	if (*str != 'f' && *str != 'e' && *str != 'g')
		*len = ft_strlen(*print)
			- (**print == '-' || **print == ' ' || **print == '+');
	else if (*str == 'g')
		*len = ft_strclen(*print, 'e') - 1
			- (**print == '-' || **print == ' ' || **print == '+')
			- 1 * (ft_strncmp((*print), "0.", 2) == 0
				|| ft_strncmp((*print), "-0.", 3) == 0);
	else if (*str == 'e')
		*len = ft_strclenc(*print, '.', 'e')
			- 1 * (ft_strchr(*print, '.') != NULL);
	else
		*len = ft_cstrlen(*print, '.');
}

static void	ft_precision(const char *str, t_specf specf, char **print, int fd)
{
	int	len;

	if (specf.precision < 0)
		return ;
	if ((*str == 'g' && specf.flags->hash == 1) || (*str != 'g' && *str != '%'
			&& *str != 's' && *str != 'c' && *str != 'p' && *str != 'n'))
	{
		ft_prec_len(str, print, &len);
		while (len < specf.precision)
		{
			if ((*str == 'd' || *str == 'i')
				&& (**print == '-' || **print == ' ' || **print == '+'))
			{
				ft_putchar_fd(**print, fd);
				(*print)++;
			}
			ft_putstr_fd("0", fd);
			len++;
		}
		if (specf.precision == 0 && (ft_strcmp(*print, " 0") == 0
				|| ft_strcmp(*print, "0") == 0 || ft_strcmp(*print, "+0") == 0))
			(*print)[(**print == ' ' || **print == '+')] = '\0';
	}
	else if (*str == 's' && ft_strlen(*print) > (size_t)specf.precision)
		(*print)[specf.precision] = '\0';
}

static void	ft_width(t_specf specf, t_print *print, int fd)
{
	while (specf.flags->zero == 0 && print->bytprint < (size_t)specf.width)
	{
		ft_putstr_fd(" ", fd);
		(print->bytprint)++;
	}
}

void	do_specf_and_print(char *str, t_specf specf, t_print *print, int fd)
{
	char	*print_aux;

	ft_bytestoprint(str, specf, print);
	ft_signedflag(str, specf, &print->content);
	if (specf.flags->minus == 0 && specf.flags->zero == 0)
		ft_width(specf, print, fd);
	ft_hashflag(str, specf, &print->content, fd);
	print_aux = print->content;
	if (specf.flags->minus == 0 && specf.flags->zero == 1)
		ft_zeroflag(str, specf, print, fd);
	if (*str != 'e' && *str != 'f' && *str != 'g')
		ft_precision(str, specf, &print->content, fd);
	if (*str == 'c')
		ft_putchar_fd(*(print->content), fd);
	else
		ft_putcstr_fd(print->content, 'e' * (*str == 'e' || *str == 'g'), fd);
	if ((*str == 'e' || *str == 'f' || *str == 'g')
		&& (*(print->content) != 'i' && *(print->content) != 'n'
			&& ft_strcmp(print->content, "-inf") != 0))
		ft_precision(str, specf, &print->content, fd);
	if (*str == 'e' || *str == 'g')
		ft_putstr_fd(ft_strchr(print->content, 'e'), fd);
	if (specf.flags->minus == 1)
		ft_width(specf, print, fd);
	free(print_aux);
}
