/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 10:34:39 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/14 10:43:21 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_strmjoin(char const *s1, char const *s2, int start)
{
	char	*str;
	char	*s1_aux;
	char	*str_aux;

	s1_aux = ft_substr(s1, 0, start);
	str = ft_strjoin(s1_aux, s2);
	free(s1_aux);
	str_aux = str;
	str = ft_strjoin(str, s1 + start);
	free(str_aux);
	return (str);
}
