/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:52:22 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:51:51 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_litoa_base(long int nbr, char *base)
{
	char			*str;
	char			*str_aux;
	int				size;

	if (nbr >= 0)
		return (ft_lutoa_base((long unsigned int)nbr, base));
	size = ft_strlen(base);
	str = ft_strdup("-");
	while (nbr != 0)
	{
		str_aux = str;
		str = ft_strcjoin(str, base[-(nbr % -size)]);
		free(str_aux);
		nbr = nbr / size;
	}
	str++;
	ft_strrev(&str);
	str--;
	return (str);
}
