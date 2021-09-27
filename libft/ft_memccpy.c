/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:29:26 by mqueguin          #+#    #+#             */
/*   Updated: 2021/07/06 13:44:43 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*buffer_dst;
	unsigned char	*buffer_src;

	i = 0;
	buffer_dst = (unsigned char *)dst;
	buffer_src = (unsigned char *)src;
	while (i < n)
	{
		buffer_dst[i] = buffer_src[i];
		if (buffer_dst[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
