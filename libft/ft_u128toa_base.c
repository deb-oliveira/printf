/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u128toa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:30:07 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:57:13 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_u128toa_base(__uint128_t nbr, char *base)
{
	unsigned int	size;
	char			*str;
	char			*str_aux;

	size = ft_strlen(base);
	if (nbr == 0)
	{
		str = ft_strcjoin("", base[0]);
		return (str);
	}
	str = ft_calloc(1, sizeof(char));
	while (nbr != 0)
	{			
		str_aux = str;
		str = ft_strcjoin(str, base[nbr % size]);
		free(str_aux);
		nbr = nbr / size;
	}
	ft_strrev(&str);
	return (str);
}
