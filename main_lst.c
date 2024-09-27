/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:20:43 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 17:01:00 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "push_swap.h" /*
#typedef t_lst;
#typedef t_program;
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
# size_t sizeof(type);
#   void free(void *);
#   void exit(int);
#        */
#include "libft/libft.h" /*
#   void **ft_free_arr(void ***);
#    int ft_fprintf(int, char *, ...);
#        */
#include "libft/ft_printf.h" /*
#    int ft_fprintf(int, char *, ...);
#        */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	lstclear(t_lst **lst);
/* *************************** [^] PROTOTYPES [^] *************************** */

void
	lstpush(t_lst **lst, register int number)
{
	t_lst	*new;

	if (!lst)
		return ;
	new = (t_lst *)malloc(sizeof(t_lst));
	if (!new)
		return ;
	new->nbr = number;
	new->next = *lst;
	*lst = new;
}

int
	lstpop(t_lst **lst)
{
	void	*tmp;
	int		nbr;

	tmp = *lst;
	nbr = (*lst)->nbr;
	*lst = (*lst)->next;
	free(tmp);
	return (nbr);
}

int
	lstsize(t_lst *lst)
{
	int	length;

	length = 0;
	while (lst)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}

void
	free_program(t_program *pro, register int err)
{
	if (pro->has_split)
		ft_free_arr((void ***)&pro->arr);
	lstclear(&pro->lst_a);
	lstclear(&pro->lst_b);
	if (err == 1)
		ft_fprintf(2, "Error\n");
	exit(err);
}

extern __inline__ void
	lstclear(t_lst **lst)
{
	void	*tmp;

	if (!lst)
		return ;
	while (!!*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}
