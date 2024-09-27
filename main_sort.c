/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:48:55 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 13:29:07 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "push_swap.h" /*
#typedef t_lst;
#   void lstpush(t_lst **, int);
#    int lstpop(t_lst **);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

char
	swap(t_lst **lst)
{
	if (!*lst || !(*lst)->next)
		return ('\n');
	(*lst)->nbr = (*lst)->nbr + (*lst)->next->nbr;
	(*lst)->next->nbr = (*lst)->nbr - (*lst)->next->nbr;
	(*lst)->nbr = (*lst)->nbr - (*lst)->next->nbr;
	return ('\n');
}

char
	rev(t_lst *lst)
{
	while (lst->next)
	{
		swap(&lst);
		lst = lst->next;
	}
	return ('\n');
}

char
	rev_rotate(t_lst *lst)
{
	if (!lst->next)
		return ('\n');
	rev_rotate(lst->next);
	swap(&lst);
	return ('\n');
}

char
	push(t_lst **first, t_lst **second)
{
	return (lstpush(second, lstpop(first)), '\n');
}
