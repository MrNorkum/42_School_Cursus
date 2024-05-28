/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:32:13 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 20:05:04 by hkeles           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* **************************** [v] INCLUDES [v] **************************** */
#include <stdlib.h> /*
# define NULL
#   void free(void *);
#        */
#include "libft.h" /*
#typedef t_list;
#   void ft_lstclear(t_list **, void (*f)(void *));
# t_list *ft_lstnew(void *);
#   void ft_lstadd_back(t_list **, t_list *);
#        */
/* **************************** [^] INCLUDES [^] **************************** */

t_list
	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*node;
	void	*content;

	if (!lst || !f)
		return (NULL);
	result = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (content == NULL)
			ft_lstclear(&result, del);
		if (content == NULL)
			return (NULL);
		node = ft_lstnew(content);
		if (!node)
		{
			free(content);
			ft_lstclear(&result, del);
			return (NULL);
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
