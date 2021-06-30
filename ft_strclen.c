/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:41:16 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/30 11:00:11 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

size_t	ft_strclen(const char *str, char c)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0' && str[size] != c)
		size++;
	return (size);
}
