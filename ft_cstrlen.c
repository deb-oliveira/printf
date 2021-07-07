/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsublen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 07:45:20 by doliveira         #+#    #+#             */
/*   Updated: 2021/07/06 12:24:48 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

size_t	ft_cstrlen(const char *str, char c)
{
	size_t	size;

	str = ft_strchr(str, c);
	if (str)
		str++;
	size = 0;
	while (str && str[size] != '\0')
		size++;
	return (size);
}