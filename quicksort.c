/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 10:44:09 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/06 11:14:47 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define bool
# define true
#        */
#include "push_swap.h" /*
#typedef t_program;
#typedef t_lst;
#   char swap(t_lst **);
#   char rev(t_lst *);
#   char rev_rotate(t_lst *);
#   char push(t_lst **, t_lst **);
#   bool is_sorted(t_lst *, char, int);
#    int lstsize(t_lst *);
#   bool sort(t_program *, int);
#   bool get_middle(int *, t_lst *, int);
#   void free_program(t_program *, int);
#        */
#include "libft/ft_printf.h" /*
#    int ft_printf(char *, ...);
#        */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ bool	quicksort_3a(t_lst **lst_a, register int len);
extern __inline__ bool	quicksort_b(t_program *pro, register int len,
							register int count);
extern __inline__ bool	quicksort_3b(t_program *pro, register int len);
/* *************************** [^] PROTOTYPES [^] *************************** */

bool
	sort(t_lst **lst_a, register int len)
{
	register int	one;
	register int	two;
	register int	three;

	if (len == 2 && (*lst_a)->nbr > (*lst_a)->next->nbr)
		ft_printf("sa%c", swap(lst_a));
	if (len == 3)
	{
		one = (*lst_a)->nbr;
		two = (*lst_a)->next->nbr;
		three = (*lst_a)->next->next->nbr;
		if (one < two && two < three)
			return (true);
		if (one < two && one > three)
			return (ft_printf("rra%c", rev_rotate((*lst_a))), sort(lst_a, 3));
		if (one > three && three > two)
			return (ft_printf("ra%c", rev((*lst_a))), sort(lst_a, 3));
		return (ft_printf("sa%c", swap(lst_a)), sort(lst_a, 3));
	}
	return (true);
}

bool
	quicksort_a(t_program *pro, register int len, register int count)
{
	register int	items;
	int				pivot;

	if (is_sorted(pro->lst_a, 'a', len))
		return (true);
	items = len;
	if (len <= 3)
	{
		if (lstsize(pro->lst_a) == 3)
			return (sort(&pro->lst_a, 3), true);
		return (quicksort_3a(&pro->lst_a, len));
	}
	if (!get_middle(&pivot, pro->lst_a, len))
		free_program(pro, 1);
	while (len != items / 2 + items % 2)
	{
		if (pro->lst_a->nbr < pivot && (len--))
			ft_printf("pb%c", push(&pro->lst_a, &pro->lst_b));
		else if (++count)
			ft_printf("ra%c", rev(pro->lst_a));
	}
	while (items / 2 + items % 2 != lstsize(pro->lst_a) && count--)
		ft_printf("rra%c", rev_rotate(pro->lst_a));
	return (quicksort_a(pro, items / 2 + items % 2, 0)
		&& quicksort_b(pro, items / 2, 0));
}

extern __inline__ bool
	quicksort_3a(t_lst **lst, int len)
{
	while (len == 2 || !is_sorted(*lst, 'a', 3))
	{
		if ((*lst)->nbr > (*lst)->next->nbr)
			ft_printf("sa%c", swap(lst));
		else if (len == 3)
			ft_printf("ra%csa%crra%c", rev(*lst), swap(lst), rev_rotate(*lst));
		if (len == 2)
			return (true);
	}
	return (true);
}

extern __inline__ bool
	quicksort_b(t_program *pro, register int len, register int count)
{
	register int	items;
	int				pivot;

	if (!count && is_sorted(pro->lst_b, 'b', len))
		while (len--)
			ft_printf("pa%c", push(&pro->lst_b, &pro->lst_a));
	if (len <= 3)
		return (quicksort_3b(pro, len));
	items = len;
	if (!get_middle(&pivot, pro->lst_b, len))
		free_program(pro, 1);
	while (len != items / 2)
	{
		if (pro->lst_b->nbr >= pivot && len--)
			ft_printf("pa%c", push(&pro->lst_b, &pro->lst_a));
		else if (++count)
			ft_printf("rb%c", rev(pro->lst_b));
	}
	while (items / 2 != lstsize(pro->lst_b) && count--)
		ft_printf("rrb%c", rev_rotate(pro->lst_b));
	return (quicksort_a(pro, items / 2 + items % 2, 0)
		&& quicksort_b(pro, items / 2, 0));
}

extern __inline__ bool
	quicksort_3b(t_program *pro, register int len)
{
	t_lst	*lst_a;
	t_lst	*lst_b;

	lst_a = pro->lst_a;
	lst_b = pro->lst_b;
	if (len == 1)
		ft_printf("pa%c", push(&lst_b, &lst_a));
	else if (len == 2)
	{
		if (lst_b->nbr < lst_b->next->nbr)
			ft_printf("sb%c", swap(&lst_b));
		while (len--)
			ft_printf("pa%c", push(&lst_b, &lst_a));
	}
	else if (len != 3)
		return (true);
	while (len)
	{
		if (len == 1 && lst_a->nbr > lst_a->next->nbr)
			ft_printf("sa%c", swap(&lst_a));
		else if (len == 1 || (len >= 2 && lst_b->nbr > lst_b->next->nbr)
			|| (len == 3 && lst_b->nbr > lst_b->next->next->nbr))
			ft_printf("pa%c", push(&lst_b, &lst_a) * (--len != -1));
		else
			ft_printf("sb%c", swap(&lst_b));
	}
	return (true);
}
