/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_etoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 14:32:51 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/25 11:47:47 by doliveira        ###   ########.fr       */
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
	else
		(*fnum)[fnum_len - 1] = (*fnum)[fnum_len - 1] + 1;
}

char	*ft_etoa_base(double f, int n, char *base)
{
	char	*fstr;
	char	*estr;
	char	*estr_aux;
	char	*num;
	int		count;

	fstr = ft_ftoa_base(f, n, base);
	count = ft_strchr(fstr, '.') - fstr;
	if (count == 1)
	{
		estr = ft_strjoin(fstr, "e+00");
		free(fstr);
		return (estr);
	}
	estr = ft_strxdup(fstr, '.');
	estr_aux = estr;
	estr = ft_substr(estr, 0, n + 2);
	free(estr_aux);
	if (ft_strlen(estr) >= n + 1)
		get_round(&estr);
	estr_aux = estr;
	estr = ft_substr(estr, 0, n + 1);
	free(estr_aux);
	estr_aux = estr;
	estr = ft_strmjoin(estr, ".", 1);
	free(estr_aux);
	estr_aux = estr;
	if (count <=9)
		estr = ft_strjoin(estr, "e+0");
	else
		estr = ft_strjoin(estr, "e+");
	free(estr_aux);
	estr_aux = estr;
	num = ft_itoa(count - 1);
	estr = ft_strjoin(estr, num);
	free(num);
	free(estr_aux);
	free(fstr);
	return (estr);
}
