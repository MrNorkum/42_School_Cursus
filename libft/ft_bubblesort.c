/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubblesort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:40:10 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 13:21:49 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdbool.h> /*
# define bool
# define true
# define false
#        */
/* **************************** [^] INCLUDES [^] **************************** */

bool
    ft_swap(int *a, int *b)
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
    return (true);
}

void
    ft_bubblesort(int *arr, register int size)
{
    register int    idx;
    register bool   is_swap;

    is_swap = true;
    while (is_swap)
    {
        is_swap = false;
        idx = -1;
        while (++idx < size - 1)
        {
            if (arr[idx] > arr[idx + 1])
                is_swap = ft_swap(&arr[idx], &arr[idx + 1]);
        }
    }
}
