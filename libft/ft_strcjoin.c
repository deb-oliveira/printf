/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 15:16:46 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:54:58 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcjoin(char const *s1, char c)
{
	char	*str;
	char	*str_aux;

	str = ft_calloc(2, sizeof(char));
	str[0] = c;
	str_aux = str;
	str = ft_strjoin(s1, str);
	free(str_aux);
	return (str);
}
