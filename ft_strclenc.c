/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclenc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 11:02:42 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/30 11:04:15 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

size_t	ft_strclenc(const char *str, char c1, char c2)
{
	size_t	size;

	size = 0;
	while (*str != '\0' && *str != c1)
		str++;
	while (str[size] != '\0' && str[size] != c2)
		size++;
	return (size);
}