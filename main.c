/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:10:00 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/06 11:09:20 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "push_swap.h" /*
#typedef t_program;
#   void free_program(t_program *, int);
#   bool isnumeric(char *);
#    int ps_atoi(char *, t_program *);
#   bool repeat(t_lst *, int);
#   void lstpush(t_lst **, int);
#   void sort(t_program *, int);
#   bool quicksort_a(t_program *, int, int);
#        */
#include <stdlib.h> /*
# define NULL
#        */
#include <stdbool.h> /*
# define false
# define true
#        */
#include "libft/libft.h" /*
#   char **ft_split(char *, char);
#    int word_count(char *, char);
#        */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	push_swap(t_program *pro);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(int argc, char *argv[])
{
	t_program	pro;

	pro.lst_a = NULL;
	pro.lst_b = NULL;
	pro.has_split = false;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		pro.arr = ft_split(argv[1], ' ');
		if (!pro.arr)
			free_program(&pro, 1);
		pro.has_split = true;
		pro.count = word_count(argv[1], ' ');
	}
	else
	{
		pro.arr = argv + 1;
		pro.count = argc - 1;
	}
	return (push_swap(&pro), 0);
}

extern __inline__ void
	push_swap(t_program *pro)
{
	register int	idx;
	register int	num;

	idx = -1;
	while (++idx < pro->count)
	{
		if (!isnumeric(pro->arr[idx]))
			free_program(pro, 1);
	}
	while (--idx > -1)
	{
		num = ps_atoi(pro->arr[idx], pro);
		if (repeat(pro->lst_a, num))
			free_program(pro, 1);
		lstpush(&pro->lst_a, num);
	}
	if (2 <= pro->count && pro->count <= 3)
		sort(&pro->lst_a, pro->count);
	else if (pro->count > 3)
		quicksort_a(pro, pro->count, 0);
	free_program(pro, 0);
}
