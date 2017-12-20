/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labrown <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:52:40 by labrown           #+#    #+#             */
/*   Updated: 2017/12/18 15:52:41 by labrown          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char			*d;

	if (!(d = (char*)malloc(sizeof(*d) * n + 1)))
		return (NULL);
	d = ft_strncpy(d, s, n);
	d[n] = '\0';
	return (d);
}
