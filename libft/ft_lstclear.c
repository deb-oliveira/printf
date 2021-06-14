/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 00:48:29 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/05/24 15:16:25 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*actual_ptr;
	t_list	*next_ptr;

	if (!lst || !del)
		return ;
	actual_ptr = *lst;
	while (actual_ptr != NULL)
	{
		next_ptr = actual_ptr->next;
		ft_lstdelone(actual_ptr, del);
		actual_ptr = next_ptr;
	}
	*lst = NULL;
}
