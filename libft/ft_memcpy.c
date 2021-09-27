/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:15:49 by mqueguin          #+#    #+#             */
/*   Updated: 2021/07/06 13:45:37 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*buffer_dst;
	char	*buffer_src;

	buffer_dst = (char *)dst;
	buffer_src = (char *)src;
	if (dst == src)
		return (dst);
	while (n--)
		*buffer_dst++ = *buffer_src++;
	return (dst);
}
