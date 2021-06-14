/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 15:11:11 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/14 15:14:58 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putmem_fd(char *s, int n, int fd)
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
