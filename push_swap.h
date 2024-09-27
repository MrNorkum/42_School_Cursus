/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:07:10 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/06 11:07:55 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 202406

/* **************************** [v] INCLUDES [v] **************************** */
# include <stdbool.h> /*
#  define bool
#         */
/* **************************** [^] INCLUDES [^] **************************** */
/* **************************** [v] STRUCTS [v] ***************************** */
struct s_lst
{
	long			nbr;
	struct s_lst	*next;
};

struct s_program
{
	char			**arr;
	int				count;
	bool			has_split;
	struct s_lst	*lst_a;
	struct s_lst	*lst_b;
};
/* **************************** [^] STRUCTS [^] ***************************** */
/* **************************** [v] TYPEDEF [v] ***************************** */
typedef struct s_lst		t_lst;
typedef struct s_program	t_program;
/* **************************** [^] TYPEDEF [^] ***************************** */
/* ************************** [v] ./main_lst.c [v] ************************** */
extern void			lstpush(t_lst **lst, int number);
extern int			lstpop(t_lst **lst);
extern int			lstsize(t_lst *lst);
extern void			free_program(t_program *pro, register int err);
/* ************************** [^] ./main_lst.c [^] ************************** */
/* ************************* [v] ./main_sort.c [v] ************************** */
extern char			swap(t_lst **lst);
extern char			rev(t_lst *lst);
extern char			rev_rotate(t_lst *lst);
extern char			push(t_lst **first, t_lst **second);
/* ************************* [^] ./main_sort.c [^] ************************** */
/* *************************** [v] ./utils.c [v] **************************** */
extern bool			isnumeric(char *str);
extern bool			repeat(t_lst *lst, int nbr);
extern int			ps_atoi(const char *str, t_program *pro);
extern bool			is_sorted(t_lst *lst, register char c, register int len);
extern bool			get_middle(int *pivot, t_lst *lst, register int len);
/* *************************** [^] ./utils.c [^] **************************** */
/* ************************* [v] ./quicksort.c [v] ************************** */
extern bool			sort(t_lst **lst_a, register int len);
extern bool			quicksort_a(t_program *pro, register int len,
						register int count);
/* ************************* [^] ./quicksort.c [^] ************************** */
#endif /* PUSH_SWAP_H */
