/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:54:37 by labrown           #+#    #+#             */
/*   Updated: 2017/12/18 15:54:39 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(const char *s1, const char *s2, size_t l)
{
	char	*s;
	char	*t;
	int		n;

	n = ft_strlen(s1) + ++l;
	s = ft_strnew(n);
	t = s;
	while (*s1)
		*s++ = *s1++;
	while (*s2 && --l > 0)
		*s++ = *s2++;
	*s = '\0';
	return (t);
}
