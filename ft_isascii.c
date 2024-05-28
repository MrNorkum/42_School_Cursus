/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkeles <hkeles@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:18:03 by hkeles            #+#    #+#             */
/*   Updated: 2024/05/23 15:18:06 by hkeles           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int
	ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}
