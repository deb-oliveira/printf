/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-oliv <dde-oliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:07:14 by dde-oliv          #+#    #+#             */
/*   Updated: 2021/07/08 08:50:56 by dde-oliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_ft2free(t_functions ft, t_list **s, va_list *arg, char **str)
{
	t_list	*lst;

	*s = malloc(1 * sizeof(t_list));
	lst = *s;
	ft.f1arg = va_arg(*arg, char *(*)(char *));
	lst->content = va_arg(*arg, char *);
	*str = ft.f1arg(lst->content);
	lst->next = NULL;
}

static void	ft_ft3free(t_functions ft, t_list **s, va_list *arg, char **str)
{
	t_list	*lst;

	*s = malloc(1 * sizeof(t_list));
	lst = *s;
	lst->next = malloc(1 * sizeof(t_list));
	ft.f2arg = va_arg(*arg, char *(*)(char *, char *));
	lst->content = va_arg(*arg, char *);
	lst->next->content = va_arg(*arg, char *);
	*str = ft.f2arg(lst->content, lst->next->content);
	lst->next->next = NULL;
}

static void	ft_ft4free(t_functions ft, t_list **s, va_list *arg, char **str)
{
	t_list	*lst;

	*s = malloc(1 * sizeof(t_list));
	lst = *s;
	lst->next = malloc(1 * sizeof(t_list));
	lst->next->next = malloc(1 * sizeof(t_list));
	ft.f3arg = va_arg(*arg, char *(*)(char *, char *, char *));
	lst->content = va_arg(*arg, char *);
	lst->next->content = va_arg(*arg, char *);
	lst->next->next->content = va_arg(*arg, char *);
	*str = ft.f3arg(lst->content, lst->next->content, lst->next->next->content);
	lst->next->next->next = NULL;
}

char	*ft_ftfree(int n, ...)
{
	va_list		arg;
	t_list		*s;
	t_functions	*ft;
	char		*str;

	str = NULL;
	ft = ft_calloc(1, sizeof(t_functions));
	va_start(arg, n);
	if (n == 2)
		ft_ft2free(*ft, &s, &arg, &str);
	else if (n == 3)
		ft_ft3free(*ft, &s, &arg, &str);
	else if (n == 4)
		ft_ft4free(*ft, &s, &arg, &str);
	ft_lstclear(&s, &free);
	va_end(arg);
	free(ft);
	return (str);
}
