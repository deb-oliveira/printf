/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doliveira <doliveira@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 14:37:35 by doliveira         #+#    #+#             */
/*   Updated: 2021/06/11 20:01:08 by doliveira        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

char	*ft_itoa_base(int nbr, char *base)
{
	unsigned int	nbr_aux;
	char			*str;
	char			*str_aux;

	nbr_aux = 0;
	if (nbr >= 0)
		return (ft_utoa_base((unsigned int)nbr, base));
	nbr_aux = (unsigned int)(-1 * (nbr + 1)) + 1;
	str = ft_utoa_base(nbr_aux, base);
	str_aux = str;
	str = ft_strjoin("-", str);
	free(str_aux);
	return (str);
}
