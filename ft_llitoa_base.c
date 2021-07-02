/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 17:53:06 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/02 17:53:40 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_llitoa_base(long long int nbr, char *base)
{
	unsigned int	nbr_aux;
	char			*str;
	char			*str_aux;

	nbr_aux = 0;
	if (nbr >= 0)
		return (ft_llutoa_base((long long unsigned int)nbr, base));
	nbr_aux = (long long unsigned int)(-1 * (nbr + 1)) + 1;
	str = ft_llutoa_base(nbr_aux, base);
	str_aux = str;
	str = ft_strjoin("-", str);
	free(str_aux);
	return (str);
}
