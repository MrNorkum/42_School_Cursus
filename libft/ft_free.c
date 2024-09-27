/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 06:27:04 by hkeles            #+#    #+#             */
/*   Updated: 2024/06/05 16:56:50 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#   void free(void *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

void
	*ft_free(void **ptr)
{
	if (!!ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return (NULL);
}

void
	**ft_free_arr(void ***ptr)
{
	size_t	i;

	if (!ptr || !*ptr)
		return (NULL);
	i = 0;
	while ((*ptr)[i])
	{
		ft_free(&(*ptr)[i]);
		i++;
	}
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}
