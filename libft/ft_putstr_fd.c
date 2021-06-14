/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:29:38 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/06/01 13:23:01 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	slen;
	int	count;

	if (!s)
		return ;
	count = 0;
	slen = ft_strlen(s);
	while (count < slen)
	{
		write(fd, &s[count], 1);
		count++;
	}
}
