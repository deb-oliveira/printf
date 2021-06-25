/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:43:29 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/23 18:49:02 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

static char	*get_ieee754 (double f)
{
	t_fbits	fnum;
	char	*fbits;
	int		size;
	int		count;

	fnum.f = f;
	size = sizeof (f) * 8;
	fbits = malloc(size + 1);
	if (!fbits)
		return (NULL);
	count = 0;
	while (size--)
	{
		fbits[count] = '0' + ((fnum.u >> size) & 1);
		count++;
	}
	fbits[count] = '\0';
	return (fbits);
}

static void	*get_exceptions(double f, char **fstr)
{
	char	*fbits;
	char	*expoent;
	char	*mantissa;

	fbits = get_ieee754(f);
	expoent = ft_substr(fbits, 1, 11);
	mantissa = ft_substr(fbits, 12, 52);
	if (ft_strcmp(expoent, "11111111111") == 0 && ft_strcmp
		(mantissa, "0000000000000000000000000000000000000000000000000000") != 0)
		*fstr = strdup("nan");
	else if (fbits[0] == '0' && ft_strcmp(expoent, "11111111111") == 0)
		*fstr = strdup("inf");
	else if (ft_strcmp(expoent, "11111111111") == 0)
		*fstr = strdup("-inf");
	free(fbits);
	free(expoent);
	free(mantissa);
}

static void	*get_round(char **fnum)
{
	char	*fnum_aux;
	size_t	fnum_len;

	fnum_len = ft_strlen(*fnum);
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

static char	*get_float(char **fnum, char *fpoint)
{
	char	*fnum_aux;
	char	*fpoint_aux;
	char	*fstr;

	fpoint_aux = fpoint;
	if (ft_strchr(fpoint, '.'))
	{
		get_round(fnum);
		fpoint = fpoint + 2;
	}
	fnum_aux = *fnum;
	*fnum = ft_strjoin(*fnum, ".");
	free(fnum_aux);
	fnum_aux = *fnum;
	fstr = ft_strjoin(*fnum, fpoint);
	free(fnum_aux);
	free(fpoint_aux);
	return (fstr);
}

char	*ft_ftoa_base(double f, int n, char *base)
{
	char		*fnum;
	char		*fpoint;
	char		*fstr;
	__uint128_t	num;

	fstr = NULL;
	num = f;
	get_exceptions(f, &fstr);
	if (fstr)
		return (fstr);
	fnum = ft_u128toa_base(num, base);
	fpoint = ft_dpointtoa_base((f - (double)num), base, n);
	fstr = get_float (&fnum, fpoint);
	return (fstr);
}
