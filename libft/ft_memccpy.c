/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:03:41 by labrown           #+#    #+#             */
/*   Updated: 2017/12/17 19:03:43 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	while (n)
	{
		*((char*)s1) = *((char*)s2);
		s1 = (void*)((char*)s1 + 1);
		s2 = (void*)((char*)s2 + 1);
		if ((char)(c) == *((char*)s1 - 1))
		{
			return (s1);
		}
		n--;
	}
	return (NULL);
}
