/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 07:50:13 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:59:52 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_zeros_and_point_out(char **gstr)
{
	int		idx;
	char	*gstr_aux;

	idx = ft_strclen(*gstr, 'e') - 1;
	if (idx == 0 || !ft_strchr(*gstr, '.')
		|| ((*gstr)[idx] != '0' && (*gstr)[idx] != '.'))
		return ;
	else
	{
		(*gstr)[idx] = '\0';
		gstr_aux = *gstr;
		*gstr = ft_strjoin(*gstr, &(*gstr)[idx + 1]);
		free(gstr_aux);
		return (get_zeros_and_point_out(gstr));
	}
}

static void	get_gstr(char **gstr, int exp)
{
	char	*gstr_aux;
	int		idx;

	idx = (**gstr == '-');
	while (exp-- > 0 && ++idx)
		ft_swap(&(*gstr)[idx], &(*gstr)[idx + 1]);
	while (++exp < 0)
	{
		gstr_aux = *gstr;
		*gstr = ft_strxdup(*gstr, '.');
		free(gstr_aux);
		gstr_aux = *gstr;
		*gstr = ft_strmjoin(*gstr, "0.", 1 * (**gstr == '-'));
		free(gstr_aux);
	}
	(*gstr)[ft_strclen(*gstr, 'e')] = '\0';
	*gstr = ft_ftfree(2, &ft_strdup, *gstr);
}

char	*ft_gtoa(long double f, int precision)
{
	char	*gstr;
	int		exp;

	gstr = ft_etoa(f, precision - 1);
	if ((!ft_isdigit(*gstr) && *gstr != '-') || ft_strcmp(gstr, "-inf") == 0)
		return (gstr);
	exp = ft_atoi(ft_strchr(gstr, 'e') + 1);
	if (exp >= -4 && exp < precision)
		get_gstr(&gstr, exp);
	get_zeros_and_point_out(&gstr);
	return (gstr);
}
