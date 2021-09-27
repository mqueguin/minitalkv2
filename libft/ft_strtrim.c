/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqueguin <mqueguin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:08:21 by mqueguin          #+#    #+#             */
/*   Updated: 2021/07/06 14:05:42 by mqueguin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char c, const char *set)
{
	int		i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	size;
	size_t	i;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (ft_check(*s1, set))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_check((s1[--size]), set))
		;
	str = (char *)malloc(sizeof(char) * (size + 2));
	if (str == NULL)
		return (NULL);
	while (i <= size)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
