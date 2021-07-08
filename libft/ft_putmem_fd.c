/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:11:11 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:54:17 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putmem_fd(const char *s, int n, int fd)
{
	int	count;

	if (!s)
		return ;
	count = 0;
	while (count < n)
	{
		write(fd, &s[count], 1);
		count++;
	}
}
