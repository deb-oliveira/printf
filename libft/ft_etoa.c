/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:32:51 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:59:28 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_round(char **estr, int precision)
{
	int		idx;
	char	*estr_aux;

	idx = ft_strlen(*estr) - 1;
	if (idx > precision + 1)
	{
		if (((*estr)[idx - 1] == '5' && (*estr)[idx] != '0'))
			(*estr)[idx - 1] = '6';
		(*estr)[idx] = '\0';
		idx--;
	}
	if (idx > precision && (*estr)[idx] >= '5')
	{
		while (--idx >= 0 && (*estr)[idx] == '9')
			(*estr)[idx] = '0';
		if (idx == -1)
			*estr = ft_ftfree(3, &ft_strjoin, ft_strdup("1"), *estr);
		else if ((*estr)[idx] % 2 != 0 || (*estr)[idx + 1] != '5')
			(*estr)[idx] = (*estr)[idx] + 1;
	}
	estr_aux = *estr;
	*estr = ft_substr(*estr, 0, precision + 1);
	free(estr_aux);
}

static void	add_exp(char **e, int precision, int exp, int sig)
{
	char	*e_aux;
	char	*expstr;

	if (precision != 0)
	{
		e_aux = *e;
		*e = ft_strmjoin(*e, ".", 1);
		free(e_aux);
	}
	expstr = ft_itoa(exp);
	if (-10 < exp && exp < 0)
	{
		e_aux = expstr;
		expstr = ft_strmjoin(expstr, "0", 1);
		free(e_aux);
	}
	if (0 <= exp && exp < 10)
		*e = ft_ftfree(4, &ft_str3join, *e, ft_strdup("e+0"), expstr);
	else if (0 < exp)
		*e = ft_ftfree(4, &ft_str3join, *e, ft_strdup("e+"), expstr);
	else
		*e = ft_ftfree(4, &ft_str3join, *e, ft_strdup("e"), expstr);
	if (sig == -1)
		*e = ft_ftfree(3, &ft_strjoin, ft_strdup("-"), *e);
}

char	*ft_etoa(long double f, int precision)
{
	char	*estr;
	char	*estr_aux;
	int		exp;

	exp = 0;
	while (-1.0 < f && f < 1.0 && f != 0.0)
	{
		f = f * 10;
		exp--;
	}
	estr = ft_ftoa(f, precision + 2);
	if ((!ft_isdigit(*estr) && *estr != '-') || ft_strcmp(estr, "-inf") == 0)
		return (estr);
	exp += ft_strclen(estr, '.') - 1 - (f < 0.0);
	estr_aux = estr;
	estr = ft_strxdup(estr + (f < 0.0), '.');
	free(estr_aux);
	estr_aux = estr;
	estr = ft_substr(estr, 0, precision + 3);
	free(estr_aux);
	get_round(&estr, precision);
	add_exp(&estr, precision, exp, (f >= 0.0) + (f < 0.0) * (-1));
	return (estr);
}
