/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:19:02 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 15:19:04 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
