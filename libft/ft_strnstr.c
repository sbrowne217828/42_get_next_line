/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:56:16 by labrown           #+#    #+#             */
/*   Updated: 2017/12/18 15:56:18 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s, char const *f, size_t n)
{
	size_t	len;

	if (*f == '\0')
		return ((char *)s);
	len = ft_strlen(f);
	while (*s != '\0' && n >= len)
	{
		if (ft_strncmp(s, f, len) == 0)
			return ((char *)s);
		s++;
		n--;
	}
	return (NULL);
}
