/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:49:59 by labrown           #+#    #+#             */
/*   Updated: 2017/12/18 15:50:01 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		s1l;
	size_t		s2l;

	i = 0;
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	if (n <= s1l)
		return (s2l + n);
	while ((s1[i] != '\0') && i < (n - 1))
		i++;
	while (*s2 && i < (n - 1))
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return (s1l + s2l);
}
