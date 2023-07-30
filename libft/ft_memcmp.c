/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:40:03 by acepni            #+#    #+#             */
/*   Updated: 2023/07/24 15:19:01 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	const unsigned char	*str1_val;
	const unsigned char	*str2_val;
	size_t				i;

	str1_val = (const unsigned char *)str1;
	str2_val = (const unsigned char *)str2;
	i = 0;
	while (i < len)
	{
		if (str1_val[i] != str2_val[i])
		{
			return (str1_val[i] - str2_val[i]);
		}
		i++;
	}
	return (0);
}
