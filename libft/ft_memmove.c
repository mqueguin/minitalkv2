/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:46:01 by mqueguin          #+#    #+#             */
/*   Updated: 2021/07/06 13:45:53 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t			i;
	unsigned char	*buffer_dst;
	unsigned char	*buffer_src;

	buffer_dst = (unsigned char *)dst;
	buffer_src = (unsigned char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	if (buffer_src < buffer_dst)
	{
		while (++i <= size)
			buffer_dst[size - i] = buffer_src[size - i];
	}
	else
		ft_memcpy(dst, src, size);
	return (dst);
}
