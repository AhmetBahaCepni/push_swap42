/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acepni <acepni@42.tr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 20:59:20 by acepni            #+#    #+#             */
/*   Updated: 2023/07/24 15:19:01 by acepni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str,
	const char *sub_str, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!sub_str[j])
		return ((char *)(str));
	while (str[i] && sub_str[j] && len)
	{
		if (str[i] == sub_str[j])
			j++;
		else if (j)
		{
			j = 0;
			continue ;
		}
		i++;
		len--;
	}
	if (!sub_str[j])
		return ((char *)(str + i - j));
	return (0);
}
