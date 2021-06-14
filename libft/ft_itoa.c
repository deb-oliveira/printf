/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 00:57:00 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/02 00:32:52 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 0)
	{
		result = result * nb;
		power--;
	}
	return (result);
}

static void	ft_buildstr(int n, int size, char **str, int *isneg)
{
	if (n < 0)
		*str = ft_calloc(size + 2, sizeof(char));
	else
		*str = ft_calloc(size + 1, sizeof(char));
	if (*str && n < 0)
	{
		*str[0] = '-';
		*isneg = 1;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		idx;
	int		alg;
	int		isneg;

	size = 1;
	while (size < 10 && (n / ft_power(10, size)) != 0)
		size++;
	isneg = 0;
	ft_buildstr(n, size, &str, &isneg);
	if (!str)
		return (NULL);
	idx = 0;
	while (size > idx)
	{
		alg = (1 - 2 * isneg) * (n / ft_power(10, size - idx - 1));
		str[idx + isneg] = 48 + alg;
		n = n - (1 - 2 * isneg) * (alg * ft_power(10, size - idx - 1));
		idx++;
	}
	return (str);
}
