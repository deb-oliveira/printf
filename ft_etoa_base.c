/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:32:51 by doliveira         #+#    #+#             */
/*   Updated: 2021/07/01 07:12:32 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static void	get_round(char **fnum)
{
	char	*fnum_aux;
	size_t	fnum_len;

	fnum_len = ft_strlen(*fnum);
	if ((*fnum)[fnum_len - 1] < '5')
		return ;
	fnum_len--;
	while (fnum_len > 0 && (*fnum)[fnum_len - 1] == '9')
	{
		(*fnum)[fnum_len - 1] = '0';
		fnum_len--;
	}
	if (fnum_len == 0)
	{
		fnum_aux = *fnum;
		*fnum = ft_strjoin("1", *fnum);
		free(fnum_aux);
	}
	else if ((*fnum)[fnum_len - 1] % 2 != 0)
		(*fnum)[fnum_len - 1] = (*fnum)[fnum_len - 1] + 1;
	else if ((*fnum)[fnum_len] != '5')
		(*fnum)[fnum_len - 1] = (*fnum)[fnum_len - 1] + 1;
}

static void	add_e(char **estr, int n, int exp, int sig)
{
	char	*estr_aux;
	char	*num;

	estr_aux = *estr;
	*estr = ft_substr(*estr, 0, n + 1);
	free(estr_aux);
	if (n != 0)
	{
		estr_aux = *estr;
		*estr = ft_strmjoin(*estr, ".", 1);
		free(estr_aux);
	}
	estr_aux = *estr;
	if (0 < exp && exp <= 9)
		*estr = ft_strjoin(*estr, "e+0");
	else if (0 < exp)
		*estr = ft_strjoin(*estr, "e+");
	else if (-9 < exp && exp <= 0)
		*estr = ft_strjoin(*estr, "e-0");
	else
		*estr = ft_strjoin(*estr, "e-");
	free(estr_aux);
	estr_aux = *estr;
	num = ft_itoa(exp - 1);
	*estr = ft_strjoin(*estr, num + 1*(*num == '-'));
	free(num);
	free(estr_aux);
	if (sig == -1)
	{
		estr_aux = *estr;
		*estr = ft_strjoin("-", *estr);
		free(estr_aux);
	}
}

char	*ft_etoa_base(long double f, int n, char *base)
{
	char	*fstr;
	char	*estr;
	char	*estr_aux;
	int		count;
	int		sig;

	count = 0;
	while(-1.0 < f && f < 1.0 && f != 0.0)
	{
		f = f * 10;
		count--;
	}
	fstr = ft_ftoa_base(f, n, base);
	if (!ft_isdigit(*fstr) && (*fstr != '-' || (*fstr == '-' && !ft_isdigit(fstr[1]))))
		return(fstr);	
	sig = 1;
	if (f < 0.0)
	{
		fstr++;
		sig = -1;
	}
	//if (*fstr == '0')
	//	ft_substr(fstr, , )
	count += ft_strchr(fstr, '.') - fstr;
	if (n == 0)
		fstr[ft_strchr(fstr, '.') - fstr] = '\0';
	if (count == 1)
	{
		estr = ft_strjoin(fstr, "e+00");
		if (sig == -1)
		{
			estr_aux = estr;
			estr = ft_strjoin("-", estr);
			free(estr_aux);
			fstr--;
		}
		free(fstr);
		return (estr);
	}
	estr = ft_strxdup(fstr, '.');
	estr_aux = estr;
	estr = ft_substr(estr, 0, n + 2);
	free(estr_aux);
	if (ft_strlen(estr) > (size_t)n + 1)
		get_round(&estr);
	add_e(&estr, n, count, sig);
	if (sig == -1)
		fstr--;
	free(fstr);
	return (estr);
}
