/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 11:00:02 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/01 21:01:20 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overflow(long int num, const char *str)
{
	if (0 < num && (LONG_MAX / 10 < num
			|| (LONG_MAX / 10 == num && LONG_MAX % 10 < *str - 48)))
		return (1);
	else if (0 > num && (LONG_MIN / 10 > num
			|| (LONG_MIN / 10 == num && -(LONG_MIN % -10) < *str - 48)))
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			sig;
	int			is_overflow;
	long int	num;

	sig = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{	
		if (*str == '-')
			sig = sig * (-1);
		str++;
	}
	while (47 < *str && *str < 58)
	{
		is_overflow = ft_overflow(num * sig, str);
		if (is_overflow == 1)
			return ((int) LONG_MAX);
		else if (is_overflow == -1)
			return ((int) LONG_MIN);
		num = (10 * num + (*str - 48));
		str++;
	}
	return ((int)(sig * num));
}
