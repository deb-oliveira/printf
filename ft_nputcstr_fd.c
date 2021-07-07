/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 18:29:28 by doliveira         #+#    #+#             */
/*   Updated: 2021/07/05 09:20:07 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_nputcstr_fd(char *s, char c, int fd, size_t *n)
{
	if (!s)
		return (NULL);
	while (*s && *s != c)
	{
		write(fd, s, 1);
		s++;
		(*n)++;
	}
	if (*s == c)
		s++;
	return (s);
}
