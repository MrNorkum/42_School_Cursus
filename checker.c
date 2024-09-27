/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 08:01:07 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 17:03:32 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include "push_swap.h" /*
#typedef t_program;
#   void free_program(t_program *, int);
#   bool isnumeric(char *);
#        */
#include <stdbool.h> /*
# define bool
# define false
# define true
#        */
#include <stdlib.h> /*
# define NULL
#        */
#include "libft/libft.h" /*
#   char **ft_split(char *, char);
#    int word_count(char *, char);
#   void ft_free_array(void ***);
#        */
#include "libft/ft_printf.h" /*
#    int ft_fprintf(int, char *, ...);
#        */
/* **************************** [^] INCLUDES [^] **************************** */
/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	checker(t_program *pro);
extern __inline__ bool	checker_control(t_program *pro);
extern __inline__ bool	first_part(t_program *pro, char *input);
extern __inline__ bool	second_part(t_program *pro, char *input);
/* *************************** [^] PROTOTYPES [^] *************************** */

int
	main(int argc, char *argv[])
{
	t_program	pro;

	if (argc == 1)
		return (0);
	pro.lst_a = NULL;
	pro.lst_b = NULL;
	pro.has_split = false;
	if (argc == 2)
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
	return (checker(&pro), 0);
}

extern __inline__ void
	checker(t_program *pro)
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
	if (checker_control(pro))
		ft_fprintf(1, "\033[0;32mOK\n\033[0;0m");
	else
		ft_fprintf(1, "\033[0;31mKO\n\033[0;0m");
	free_program(pro, 0);
}

extern __inline__ bool
	checker_control(t_program *pro)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		if (first_part(pro, input))
			;
		else if (second_part(pro, input))
			;
		else
		{
			free(input);
			free_program(pro, 1);
		}
		free(input);
		input = get_next_line(0);
	}
	if (!is_sorted(pro->lst_a, 'a', pro->count) || lstsize(pro->lst_b))
		return (false);
	return (true);
}

extern __inline__ bool
	first_part(t_program *pro, char *input)
{
	if (!ft_strncmp(input, "sa\n", 3))
		swap(&pro->lst_a);
	else if (!ft_strncmp(input, "sb\n", 3))
		swap(&pro->lst_b);
	else if (!ft_strncmp(input, "ra\n", 3))
		rev(pro->lst_a);
	else if (!ft_strncmp(input, "rb\n", 3))
		rev(pro->lst_b);
	else if (!ft_strncmp(input, "rra\n", 4))
		rev_rotate(pro->lst_a);
	else if (!ft_strncmp(input, "rrb\n", 4))
		rev_rotate(pro->lst_b);
	else if (!ft_strncmp(input, "pa\n", 3))
		push(&pro->lst_b, &pro->lst_a);
	else if (!ft_strncmp(input, "pb\n", 3))
		push(&pro->lst_a, &pro->lst_b);
	else
		return (false);
	return (true);
}

extern __inline__ bool
	second_part(t_program *pro, char *input)
{
	if (!ft_strncmp(input, "ss\n", 3))
	{
		swap(&pro->lst_a);
		swap(&pro->lst_b);
	}
	else if (!ft_strncmp(input, "rr\n", 3))
	{
		rev(pro->lst_a);
		rev(pro->lst_b);
	}
	else if (!ft_strncmp(input, "rrr\n", 4))
	{
		rev_rotate(pro->lst_a);
		rev_rotate(pro->lst_b);
	}
	else
		return (false);
	return (true);
}
