/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:06:39 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/01 00:10:03 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		size;
	int		idx;
	int		alg;
	int		sig;

	size = 1;
	while (size < 10 && (n / ft_iterative_power(10, size)) != 0)
		size++;
	idx = 0;
	sig = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		sig = -1;
	}
	while (size > idx)
	{
		alg = sig * (n / ft_iterative_power(10, size - idx - 1));
		ft_putchar_fd(48 + alg, fd);
		n = n - sig * (alg * ft_iterative_power(10, size - idx - 1));
		idx++;
	}
}
