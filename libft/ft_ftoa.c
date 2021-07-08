/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:43:29 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 16:35:03 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_ieee754(double f)
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

static void	get_exceptions(double f, char **fstr)
{
	char	*fbits;
	char	*zeros;

	fbits = get_ieee754(f);
	zeros = ft_strdup("0000000000000000000000000000000000000000000000000000");
	if (ft_strncmp(fbits + 1, "11111111111", 11) == 0
		&& ft_strcmp(fbits + 12, zeros) != 0)
		*fstr = ft_strdup("nan");
	else if (ft_strncmp(fbits + 1, "11111111111", 11) == 0 && fbits[0] == '0')
		*fstr = ft_strdup("inf");
	else if (ft_strncmp(fbits + 1, "11111111111", 11) == 0)
		*fstr = ft_strdup("-inf");
	free(fbits);
	free(zeros);
}

static char	*get_fstr(char **fnum, char *fpoint, int sig)
{
	char	*fpoint_aux;
	char	*fstr;
	size_t	fnum_len;

	fpoint_aux = fpoint;
	if (ft_strchr(fpoint, '.'))
	{
		fnum_len = ft_strlen(*fnum);
		while (fnum_len > 0 && (*fnum)[fnum_len - 1] == '9')
		{
			(*fnum)[fnum_len - 1] = '0';
			fnum_len--;
		}
		if (fnum_len == 0)
			*fnum = ft_ftfree(3, &ft_strjoin, ft_strdup("1"), *fnum);
		else
			(*fnum)[fnum_len - 1] = (*fnum)[fnum_len - 1] + 1;
		fpoint = ft_strdup(fpoint + 2);
		free(fpoint_aux);
	}
	fstr = ft_ftfree(4, &ft_str3join, *fnum, ft_strdup("."), fpoint);
	if (sig == -1)
		fstr = ft_ftfree(3, &ft_strjoin, ft_strdup("-"), fstr);
	return (fstr);
}

char	*ft_ftoa(long double f, int precision)
{
	char		*fnum;
	char		*fpoint;
	char		*fstr;
	int			sig;
	char		*base;

	fstr = NULL;
	get_exceptions(f, &fstr);
	if (fstr)
		return (fstr);
	base = ft_strdup("0123456789");
	sig = (f >= 0.0) + (f < 0.0) * (-1);
	fnum = ft_u128toa_base(sig * (__int128_t)f, base);
	fpoint = ft_upointtoa_base(sig * f - sig * (__int128_t)f, base, precision);
	if (precision == 0 && (__int128_t)f % 2 != 0
		&& sig * f - sig * (__int128_t)f == 0.5 && *fpoint == '0')
	{
		free(fpoint);
		fpoint = ft_strdup ("1.0");
	}
	fstr = get_fstr(&fnum, fpoint, sig);
	if (precision == 0)
		fstr[ft_strchr(fstr, '.') - fstr] = '\0';
	free(base);
	return (fstr);
}
