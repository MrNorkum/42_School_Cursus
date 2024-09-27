/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:53:08 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 13:03:24 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define bool
# define false
# define true
#        */
#include "push_swap.h" /*
#typedef t_lst;
#typedef t_program;
#   void free_program(t_program *, int);
#        */
#include <stdlib.h> /*
#   void *malloc(size_t);
# size_t sizeof(type);
#   void free(void *);
#        */
#include "libft/libft.h" /*
#   void ft_bubblesort(int *, int);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

bool
	isnumeric(char *s)
{
	if (*s == 45 || *s == 43)
		s++;
	if (!*s)
		return (false);
	while (*s)
		if (!('0' <= *s && *s++ <= '9'))
			return (false);
	return (true);
}

bool
	repeat(t_lst *lst, register int nbr)
{
	if (!lst)
		return (false);
	if (lst->nbr == nbr)
		return (true);
	return (repeat(lst->next, nbr));
}

int
	ps_atoi(const char *s, t_program *pro)
{
	long	res;
	bool	sign;

	res = 0;
	sign = false;
	while (*s == ' ' || (9 <= *s && *s <= 13))
		s++;
	if (*s == 45)
		sign = true;
	if (*s == 45 || *s == 43)
		s++;
	while ('0' <= *s && *s <= '9')
	{
		res = (res * 10) + (*s++ & 15);
		if (1 + ~res < -2147483648 || res > 2147483647)
			free_program(pro, 1);
	}
	if (sign == true)
		return (1 + ~res);
	return (res);
}

bool
	is_sorted(t_lst *lst, register char c, register int len)
{
	while (c == 'a' && --len)
	{
		if (lst->nbr > lst->next->nbr)
			return (false);
		lst = lst->next;
	}
	while (c == 'b' && --len)
	{
		if (lst->nbr < lst->next->nbr)
			return (false);
		lst = lst->next;
	}
	return (true);
}

bool
	get_middle(int *pivot, t_lst *lst, register int len)
{
	register int	tmp_len;
	int				*arr;

	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (false);
	tmp_len = len;
	while (tmp_len--)
	{
		arr[tmp_len] = lst->nbr;
		lst = lst->next;
	}
	ft_bubblesort(arr, len);
	*pivot = arr[len / 2];
	free(arr);
	return (true);
}
