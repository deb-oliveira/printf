/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:45:18 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/14 12:58:49 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_strlen(char *str)
{
	int	size;

	size = 0;
	while (str[size] != '\0')
	{
		size++;
	}
	return (size);
}

int	is_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	ft_rest_div(int num, char *base, int size)
{
	char	rest_div;

	if (num > 0)
		rest_div = base[num % size];
	if (num < 0)
		rest_div = base[-(num % -size)];
	return (rest_div);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	num[33];
	int		count;
	int		size;

	size = ft_strlen(base);
	if (is_base(base) != 0 && size > 1)
	{
		count = 0;
		if (nbr < 0)
			write(1, "-", 1);
		if (nbr == 0)
			write(1, &base[0], 1);
		while (nbr != 0)
		{
			num[count] = ft_rest_div(nbr, base, size);
			nbr = nbr / size;
			count++;
		}
		count--;
		while (count >= 0)
		{
			write(1, &num[count], 1);
			count--;
		}
	}
}
