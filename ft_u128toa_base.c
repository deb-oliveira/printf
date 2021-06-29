/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u128toa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:30:07 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/29 17:35:58 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_initial_values(__int128_t nbr, char *base, char **str)
{
	if (nbr == 0)
		*str = ft_strcjoin("", base[0]);
	else if (nbr > 0)
		*str = ft_calloc(1, sizeof(char));
	else
		*str = ft_strdup("-");
}

char	*ft_128toa_base(__int128_t nbr, char *base)
{
	unsigned int	size;
	char			*str;
	char			*str_aux;

	size = ft_strlen(base);
	ft_initial_values(nbr, base, &str);
	while (nbr != 0)
	{
		str_aux = str;
		if (nbr > 0)
			str = ft_strcjoin(str, base[nbr % size]);
		else
			str = ft_strcjoin(str, base[-(nbr % size)]);
		free(str_aux);
		nbr = nbr / size;
	}
	if (*str == '-')
	{
		str++;
		ft_strrev(&str);
		str--;
	}
	else
		ft_strrev(&str);
	return (str);
}
