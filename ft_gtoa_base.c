/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gtoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 07:50:13 by dde-oliv         #+#    #+#             */
/*   Updated: 2021/07/01 07:53:22 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft/libft.h"
#include "ft_printf.h"

void	get_zeros_and_point_out(char **gstr)
{
	int		idx;
	char	*gstr_aux;

	idx = ft_strclen(*gstr, 'e') - 1;
	if (idx == 0 || !ft_strchr(*gstr, '.') || ((*gstr)[idx] != '0' && (*gstr)[idx] != '.'))
		return	;
	else
	{
		(*gstr)[idx] = '\0';
		gstr_aux = *gstr;
		*gstr = ft_strjoin(*gstr, &(*gstr)[idx + 1]);
		free(gstr_aux);
		return(get_zeros_and_point_out(gstr));
	}
}

char	*ft_gtoa_base(long double f, int n, char *base)
{
	char	*gstr;
	char	*gstr_aux;
	int		exp;
	int		idx;

	gstr = ft_etoa_base(f, n - 1, base);
	if (!ft_isdigit(*gstr) && (*gstr != '-' || (*gstr == '-' && !ft_isdigit(gstr[1]))))
		return(gstr);
	exp = ft_atoi(ft_strchr(gstr, 'e') + 1);
	if (exp < -4 || exp >= n)
	{
		get_zeros_and_point_out(&gstr);
		return (gstr);
	}
	idx = (*gstr == '-');
	while (exp-- > 0 && ++idx)
		ft_swap(&gstr[idx], &gstr[idx + 1]);
	while (++exp < 0)
	{
		gstr_aux = gstr;
		gstr = ft_strxdup(gstr, '.');
		free(gstr_aux);
		gstr_aux = gstr;
		gstr = ft_strmjoin(gstr, "0.", 1 * (*gstr == '-'));
		free(gstr_aux);
	}
	gstr_aux = gstr;
	gstr[ft_strclen(gstr, 'e')] = '\0';
	gstr = ft_strdup(gstr);
	free(gstr_aux);
	get_zeros_and_point_out(&gstr);
	return (gstr);
}
